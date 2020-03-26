#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <string>
#include <math.h>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Shader.h"

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
	glm::vec3 pos[4] = {
		glm::vec3(-0.2f, 0.2f, 0.00f),
		glm::vec3(-0.2f, -0.2f, 0.00f),
		glm::vec3(0.2f, -0.2f, 0.00f),
		glm::vec3(0.2f, 0.2f, 0.00f)
	};

	unsigned int indices[6] = {
		0, 1, 2,
		2, 3, 0
	};

	glm::vec3 pos2[4] = {
		glm::vec3(-0.3f, 0.3f, 0.00f),
		glm::vec3(-0.3f, -0.3f, 0.00f),
		glm::vec3(0.3f, -0.3f, 0.00f),
		glm::vec3(0.3f, 0.3f, 0.00f)
	};

	unsigned int indices2[6] = {
		0, 1, 2,
		2, 3, 0
	};

	VertexArray va;
	VertexBuffer vb(pos, 4 * sizeof(glm::vec3));

	VertexArray va2;
	VertexBuffer vb2(pos2, 4 * sizeof(glm::vec3));

	VertexBufferLayout layout;
	layout.Push<float>(3);
	va.AddBuffer(vb, layout);

	VertexBufferLayout layout2;
	layout2.Push<float>(3);

	IndexBuffer ib(indices, 6);
	IndexBuffer ib2(indices2, 6);

	glm::mat4 trans;
	trans = glm::scale(glm::mat4(), glm::vec3(0.5f, 0.5f, 0.5f));

	Shader shader("res/shaders/Basic.shader");
	shader.Bind();
	shader.SetUniformMat4f("u_Transform", trans);

	va.Unbind();
	va2.Unbind();
	vb.Unbind();
	vb2.Unbind();
	ib.Unbind();
	ib2.Unbind();
	shader.Unbind();
	float r = 0.0f;
	float increment = 0.05f;

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Bind();

		shader.SetUniform4f("u_Color", r, 0.4f, 0.5f, 1.0f);

		va.Bind();
		ib.Bind();
		va2.Bind();
		ib2.Bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		if (r > 1.0f)
			increment = -0.05f;
		else if (r < 0.0f)
			increment = 0.05f;
		r += increment;


		glfwSwapBuffers(window);

		glfwPollEvents();
	}

}