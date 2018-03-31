#include "Material.h"

//-----------------------------------------------------------------------------------------------------
Material::~Material() = default;
//-----------------------------------------------------------------------------------------------------
void Material::apply()
{
  m_shaderLib->useShader(m_shaderName);
  init();
}
//-----------------------------------------------------------------------------------------------------
void Material::setShaderName(const std::string &_name)
{
  m_shaderName = _name;
}
//-----------------------------------------------------------------------------------------------------
std::string Material::getShaderName() const noexcept
{
  return m_shaderName;
}
//-----------------------------------------------------------------------------------------------------
void Material::handleKey(QKeyEvent*, QOpenGLContext*)
{}
