#pragma once
#include <Gfx/Graph/Node.hpp>
#include <Gfx/Graph/RenderList.hpp>

namespace MyVfx
{
struct Renderer;
struct Node : score::gfx::ProcessNode
{
  Node();
  virtual ~Node();
  const score::gfx::Mesh& mesh() const noexcept override;

  score::gfx::NodeRenderer*
  createRenderer(score::gfx::RenderList& r) const noexcept override;

  std::unique_ptr<char[]> m_materialData;

private:
  friend Renderer;
  const score::gfx::Mesh* m_mesh{};

  QShader m_vertexS;
  QShader m_fragmentS;
};
}
