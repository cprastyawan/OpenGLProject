#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <string>
#include <math.h>
#include <user/VertexBuffer.h>
#include <user/IndexBuffer.h>
#include <user/VertexArray.h>
#include <user/VertexBufferLayout.h>
#include <user/Renderer.h>
#include <user/Shader.h>
#include <user/Triangle.h>

#define WIDTH 640
#define HEIGHT 480

static bool kondisi = false;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		std::cout << "Space Key Pressed" << std::endl;
		kondisi = true;
	}
}

int main() {
	GLFWwindow *window;

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (glfwInit() != GLFW_TRUE) {
		printf("GLFW ERROR\n");
		return -1;
	}

	window = glfwCreateWindow(640, 480, "Window 1", NULL, NULL);
	if (!window) {
		printf("Window error!\n");
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	int a = glewInit();
	if (glewInit()!=GLEW_OK) {
		printf("GLEW ERROR!\n");
		printf("%d\n", a);
		return -1;
	}

	Triangle tri(Point{ WIDTH/2, HEIGHT/2 }, Color{ 1.0f,0.0f,0.0f }, 60.0f);

	glm::mat4 Projection = glm::ortho(0.0f, (float)WIDTH, (float)HEIGHT, 0.0f, -1.0f, 1.0f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 MVP = Projection * View;

	VertexArray va;
	VertexBuffer vb(tri.pos, tri.sizeTriangle);

	VertexBufferLayout layout;
	layout.Push<float>(3);
	va.AddBuffer(vb, layout);

	VertexBufferLayout layout2;
	layout2.Push<float>(3);

	IndexBuffer ib(tri.indices, tri.indicescount);

	Shader shader("../res/shaders/Basic.shader");
	shader.Bind();

	va.Unbind();
	vb.Unbind();
	ib.Unbind();

	shader.Unbind();
	Renderer renderer;

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Bind();
		va.Bind();
		ib.Bind();
		
		renderer.AddTriangle(tri, shader, MVP);
		renderer.Draw(va, ib, shader);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

}