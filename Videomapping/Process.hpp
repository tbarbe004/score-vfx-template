#pragma once
#include <Library/LibraryInterface.hpp>
#include <Process/Drop/ProcessDropHandler.hpp>
#include <Process/GenericProcessFactory.hpp>
#include <Process/Process.hpp>

#include <Videomapping/Metadata.hpp>

namespace Videomapping
{
class Model final : public Process::ProcessModel
{
  SCORE_SERIALIZE_FRIENDS
  PROCESS_METADATA_IMPL(Videomapping::Model)
  W_OBJECT(Model)

public:
  Model(
      const TimeVal& duration,
      const Id<Process::ProcessModel>& id,
      QObject* parent);

  template <typename Impl>
  Model(Impl& vis, QObject* parent)
      : Process::ProcessModel{vis, parent}
  {
    vis.writeTo(*this);
  }

  ~Model() override;

  constexpr bool hasExternalUI() { return false; }

private:
  QString prettyName() const noexcept override;
};

using ProcessFactory = Process::ProcessFactory_T<Videomapping::Model>;
}
