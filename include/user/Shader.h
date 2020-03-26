#pragma once
#include <string>
#include <GL/glew.h>
#include <unordered_map>
#include <glm/glm.hpp>

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};


class Shader {
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	//Set Uniforms
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform1f(const std::string& name, float value);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
	
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	static ShaderProgramSource ParseShader(const std::string &filepath);

private:
	unsigned int GetUniformLocation(const std::string& name);
};