#include <iostream>
#include "Renderer.h"

void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OPENGL Error] (" << error << "): " << function <<
			" " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

Renderer::Renderer() {

}


void Renderer::Draw(const VertexArray & va, const IndexBuffer & ib, const Shader & shader) const{
	shader.Bind();
	va.Bind();
	ib.Bind();

	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
void Renderer::Clear() const {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::AddRectangle(Rectangle r, Shader& shader, glm::mat4 MVP) {
	shader.Bind();
	MVP = MVP * r.Position;
	if (r.hide) {
		shader.SetUniform4f("u_Color", 0.0f, 0.0f, 0.0f, 0.0f);
		shader.SetUniformMat4f("u_MVP", MVP);
		shader.SetUniformMat4f("u_Scale", r.ZeroScale);
	}
	else {
		shader.SetUniform4f("u_Color", r.color.red, r.color.green, r.color.blue, r.color.alpha);
		shader.SetUniformMat4f("u_MVP", MVP);
		shader.SetUniformMat4f("u_Scale", r.Scale);
	}
}