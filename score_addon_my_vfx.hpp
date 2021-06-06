#pragma once
#include <score/application/ApplicationContext.hpp>
#include <score/command/Command.hpp>
#include <score/command/CommandGeneratorMap.hpp>
#include <score/plugins/InterfaceList.hpp>
#include <score/plugins/qt_interfaces/CommandFactory_QtInterface.hpp>
#include <score/plugins/qt_interfaces/FactoryFamily_QtInterface.hpp>
#include <score/plugins/qt_interfaces/FactoryInterface_QtInterface.hpp>
#include <score/plugins/qt_interfaces/GUIApplicationPlugin_QtInterface.hpp>
#include <score/plugins/qt_interfaces/PluginRequirements_QtInterface.hpp>

#include <utility>
#include <vector>

class score_addon_my_vfx final
    : public score::Plugin_QtInterface
    , public score::FactoryInterface_QtInterface
{
  SCORE_PLUGIN_METADATA(1, "00000000-0000-0000-0000-000000000000")

public:
  score_addon_my_vfx();
  ~score_addon_my_vfx() override;

private:
  std::vector<std::unique_ptr<score::InterfaceBase>> factories(
      const score::ApplicationContext& ctx,
      const score::InterfaceKey& key) const override;

  std::vector<score::PluginKey> required() const override;
};
