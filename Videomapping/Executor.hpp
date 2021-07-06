#pragma once
#include <Process/Execution/ProcessComponent.hpp>

#include <ossia/dataflow/node_process.hpp>

namespace MyVfx
{
class Model;
class ProcessExecutorComponent final
    : public Execution::ProcessComponent_T<MyVfx::Model, ossia::node_process>
{
  COMPONENT_METADATA("fc5249c6-7ba3-4849-be2c-3141b6293a68")
public:
  ProcessExecutorComponent(
      Model& element,
      const Execution::Context& ctx,
      QObject* parent);
};

using ProcessExecutorComponentFactory
    = Execution::ProcessComponentFactory_T<ProcessExecutorComponent>;
}
