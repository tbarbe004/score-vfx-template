#include "Executor.hpp"

#include <Gfx/GfxApplicationPlugin.hpp>
#include <Gfx/GfxContext.hpp>
#include <Gfx/GfxExecNode.hpp>
#include <Gfx/Graph/PhongNode.hpp>
#include <Gfx/TexturePort.hpp>
#include <Process/Dataflow/Port.hpp>
#include <Process/ExecutionContext.hpp>

#include <score/document/DocumentContext.hpp>

#include <ossia/dataflow/port.hpp>

#include <Videomapping/Node.hpp>
#include <Videomapping/Process.hpp>
namespace Videomapping
{
class mesh_node final : public Gfx::gfx_exec_node
{
public:
  mesh_node(Gfx::GfxExecutionAction& ctx)
      : gfx_exec_node{ctx}
  {
    root_inputs().push_back(new ossia::texture_inlet);
    root_outputs().push_back(new ossia::texture_outlet);

    auto n = std::make_unique<Videomapping::Node>();

    id = exec_context->ui->register_node(std::move(n));
  }

  ~mesh_node() { exec_context->ui->unregister_node(id); }

  std::string label() const noexcept override { return "Videomapping"; }
};

ProcessExecutorComponent::ProcessExecutorComponent(
    Videomapping::Model& element,
    const Execution::Context& ctx,
    QObject* parent)
    : ProcessComponent_T{element, ctx, "VideomappingExecutorComponent", parent}
{
  try
  {
    auto n = std::make_shared<mesh_node>(
        ctx.doc.plugin<Gfx::DocumentPlugin>().exec);

    this->node = n;
    m_ossia_process = std::make_shared<ossia::node_process>(n);

    for (std::size_t i = 0; i < 6; i++)
      {
        auto ctrl = qobject_cast<Process::ControlInlet*>(element.inlets()[i]);
        auto& p = n->add_control();
        p->value = ctrl->value();

        p->changed = true;

        QObject::connect(
            ctrl,
            &Process::ControlInlet::valueChanged,
            this,
            con_unvalidated{ctx, i, 0, n});
      }

      n->root_outputs().push_back(new ossia::texture_outlet);

      this->node = n;
      m_ossia_process = std::make_shared<ossia::node_process>(n);
  }
  catch (...)
  {
  }
}
}
