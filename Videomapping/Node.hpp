#pragma once
#include <Gfx/Graph/Node.hpp>
#include <Gfx/Graph/RenderList.hpp>
#include <Gfx/Graph/CommonUBOs.hpp>

namespace Videomapping
{
class Renderer;
class Node : public score::gfx::NodeModel
{
public:
  Node();
  virtual ~Node();

  score::gfx::NodeRenderer*
  createRenderer(score::gfx::RenderList& r) const noexcept override;
  void process(const score::gfx::Message& msg) override;

private:
  score::gfx::ModelCameraUBO ubo;

  ossia::vec3f top_left, top_right, bottom_left, bottom_right;
  friend Renderer;
  QImage m_image;
};
}
