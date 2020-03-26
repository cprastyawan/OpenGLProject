#pragma once

#include <GL/glew.h>
#include <user/VertexArray.h>
#include <user/IndexBuffer.h>
#include <user/Shader.h>

#include "Rectangle.h"
#include "Triangle.h"

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__,__LINE__));


void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

class Renderer {
private:
public:
	Renderer();
	void AddRectangle(Rectangle r, Shader& shader, glm::mat4 MVP);
	void AddTriangle(Triangle t, Shader& shader, glm::mat4 MVP);
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
	void Clear() const;
};