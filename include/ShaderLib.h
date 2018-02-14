#ifndef SHADERLIB_H
#define SHADERLIB_H

#include <vector>
#include <unordered_map>
#include <QOpenGLShaderProgram>
#include <memory>

class ShaderLib
{
public:
  //-----------------------------------------------------------------------------------------------------
  /// @brief Creates a shader program from a json file, by extracting the path of all required glsl
  /// shaders for that program, compiling, attaching and linking them.
  /// @param [in] _jsonFileName is the path to the json file.
  /// @return is the name that this shader is stored under.
  //-----------------------------------------------------------------------------------------------------
  std::string loadShaderProg(const QString &_jsonFileName);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Creates a shader program and loads a vertex and fragment shader, attaching both.
  /// @param [in] _name is the name that this shader program should be stored under.
  /// @param [in] _vertexName is the file path to the vertex glsl shader.
  /// @param [in] _fragName is the file path to the fragment glsl shader.
  //-----------------------------------------------------------------------------------------------------
  void createShader(const std::string& _name, const QString &_vertexName, const QString &_fragName);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Binds a stored shader.
  /// @param [in] _name is the name of the shader program that should be bound.
  //-----------------------------------------------------------------------------------------------------
  void useShader(const std::string& _name);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Accesses a stored shader program.
  /// @param [in] _name is the name of the shader program should be accessed.
  /// @return a pointer to the specified shader.
  //-----------------------------------------------------------------------------------------------------
  QOpenGLShaderProgram* getShader(const std::string& _name);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Accesses the currently bound shader program.
  /// @return a pointer to the currently bound shader program.
  //-----------------------------------------------------------------------------------------------------
  QOpenGLShaderProgram* getCurrentShader();

private:
  //-----------------------------------------------------------------------------------------------------
  /// @brief A map from shader name to shader program, so that they can be reused and easily bound.
  //-----------------------------------------------------------------------------------------------------
  std::unordered_map<std::string, std::unique_ptr<QOpenGLShaderProgram>> m_shaderPrograms;
  //-----------------------------------------------------------------------------------------------------
  /// @brief A pointer to the currently bound shader program.
  //-----------------------------------------------------------------------------------------------------
  QOpenGLShaderProgram* m_currentShader;
};

#endif // SHADERLIB_H
