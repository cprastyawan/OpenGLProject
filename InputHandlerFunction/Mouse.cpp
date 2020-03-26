/*#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
void cursorEnterCallback(GLFWwindow* window, int entered);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

int main() {
	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HELLO WORLD", NULL, NULL);

	//glfwSetCursorPosCallback(window, cursorPositionCallback);
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	//glfwSetCursorEnterCallback(window, cursorEnterCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetScrollCallback(window, scrollCallback);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	unsigned char pixels[16 * 16 * 4];
	memset(pixels, 0xff, sizeof(pixels));
	GLFWimage image;
	image.width = 16;
	image.height = 16;
	image.pixels = pixels;
	GLFWcursor* cursor = glfwCreateCursor(&image, 0, 0);
	glfwSetCursor(window, cursor);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}

static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
	std::cout << xpos << ", " << ypos << std::endl;
}

void cursorEnterCallback(GLFWwindow* window, int entered) {
	if (entered) std::cout << "Entered window" << std::endl;
	else std::cout << "Left window" << std::endl;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		std::cout << "Right Button Pressed" << std::endl;
	}
}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	std::cout << "Mouse di scroll" << std::endl;
	
}*/