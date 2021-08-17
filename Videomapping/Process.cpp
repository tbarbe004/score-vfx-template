#include "Process.hpp"

#include <Gfx/Graph/Node.hpp>
#include <Gfx/Graph/ShaderCache.hpp>
#include <Gfx/TexturePort.hpp>
#include <Process/Dataflow/WidgetInlets.hpp>

#include <wobjectimpl.h>
W_OBJECT_IMPL(Videomapping::Model)
namespace Videomapping
{
Model::Model(
    const TimeVal& duration,
    const Id<Process::ProcessModel>& id,
    QObject* parent)
    : Process::ProcessModel{duration, id, "gfxProcess", parent}
{
  metadata().setInstanceName(*this);
  m_inlets.push_back(new Gfx::TextureInlet{Id<Process::Port>(0), this});

  ossia::vec3f min{-1., -1., 0.};
  ossia::vec3f max{1., 1., 0.};

  m_inlets.push_back(new Process::XYZSlider{
      min,
      max,
      ossia::vec3f{-1., 1., 0.},
      QString(tr("top left")),
      Id<Process::Port>(1),
      this});

  m_inlets.push_back(new Process::XYZSlider{
      min,
      max,
      ossia::vec3f{-1., 1., 0.},
      QString(tr("top right")),
      Id<Process::Port>(2),
      this});

  m_inlets.push_back(new Process::XYZSlider{
      min,
      max,
      ossia::vec3f{-1., -1., 0.},
      QString(tr("bottom left")),
      Id<Process::Port>(3),
      this});

  m_inlets.push_back(new Process::XYZSlider{
      min,
      max,
      ossia::vec3f{1., -1., 0.},
      QString(tr("bottom right")),
      Id<Process::Port>(4),
      this});

  m_outlets.push_back(new Gfx::TextureOutlet{Id<Process::Port>(0), this});
}

Model::~Model() { }

QString Model::prettyName() const noexcept
{
  return tr("My VFX");
}

}
template <>
void DataStreamReader::read(const Videomapping::Model& proc)
{
  readPorts(*this, proc.m_inlets, proc.m_outlets);

  insertDelimiter();
}

template <>
void DataStreamWriter::write(Videomapping::Model& proc)
{
  writePorts(
      *this,
      components.interfaces<Process::PortFactoryList>(),
      proc.m_inlets,
      proc.m_outlets,
      &proc);
  checkDelimiter();
}

template <>
void JSONReader::read(const Videomapping::Model& proc)
{
  readPorts(*this, proc.m_inlets, proc.m_outlets);
}

template <>
void JSONWriter::write(Videomapping::Model& proc)
{
  writePorts(
      *this,
      components.interfaces<Process::PortFactoryList>(),
      proc.m_inlets,
      proc.m_outlets,
      &proc);
}
