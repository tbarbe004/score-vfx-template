#include "score_addon_videomapping.hpp"

#include <score/plugins/FactorySetup.hpp>

#include <Videomapping/Executor.hpp>
#include <Videomapping/Layer.hpp>
#include <Videomapping/Process.hpp>
#include <score_plugin_engine.hpp>
#include <score_plugin_gfx.hpp>

score_addon_videomapping::score_addon_videomapping() { }

score_addon_videomapping::~score_addon_videomapping() { }

std::vector<std::unique_ptr<score::InterfaceBase>>
score_addon_videomapping::factories(
    const score::ApplicationContext& ctx,
    const score::InterfaceKey& key) const
{
  return instantiate_factories<
      score::ApplicationContext,
      FW<Process::ProcessModelFactory, Videomapping::ProcessFactory>,
      FW<Process::LayerFactory, Videomapping::LayerFactory>,
      FW<Execution::ProcessComponentFactory,
         Videomapping::ProcessExecutorComponentFactory>>(ctx, key);
}

auto score_addon_videomapping::required() const -> std::vector<score::PluginKey>
{
  return {score_plugin_gfx::static_key()};
}

#include <score/plugins/PluginInstances.hpp>
SCORE_EXPORT_PLUGIN(score_addon_videomapping)
