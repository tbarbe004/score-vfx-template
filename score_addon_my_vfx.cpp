#include "score_addon_my_vfx.hpp"

#include <score/plugins/FactorySetup.hpp>

#include <MyVfx/Executor.hpp>
#include <MyVfx/Layer.hpp>
#include <MyVfx/Process.hpp>
#include <score_plugin_engine.hpp>
#include <score_plugin_gfx.hpp>

score_addon_my_vfx::score_addon_my_vfx() { }

score_addon_my_vfx::~score_addon_my_vfx() { }

std::vector<std::unique_ptr<score::InterfaceBase>>
score_addon_my_vfx::factories(
    const score::ApplicationContext& ctx,
    const score::InterfaceKey& key) const
{
  return instantiate_factories<
      score::ApplicationContext,
      FW<Process::ProcessModelFactory, MyVfx::ProcessFactory>,
      FW<Process::LayerFactory, MyVfx::LayerFactory>,
      FW<Execution::ProcessComponentFactory,
         MyVfx::ProcessExecutorComponentFactory>>(ctx, key);
}

auto score_addon_my_vfx::required() const -> std::vector<score::PluginKey>
{
  return {score_plugin_gfx::static_key()};
}

#include <score/plugins/PluginInstances.hpp>
SCORE_EXPORT_PLUGIN(score_addon_my_vfx)
