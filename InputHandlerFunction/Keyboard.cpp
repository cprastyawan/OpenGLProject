/*#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define SCREEN_WIDTH 560
#define SCREEN_HEIGHT 340

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_L && action == GLFW_REPEAT) {
		std::cout << "L Key Pressed" << std::endl;
	}
}

int main() {
	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HELLO WORLD", NULL, NULL);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glViewport(0.0f, 0.0f, screenWidth, screenHeight);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}*/