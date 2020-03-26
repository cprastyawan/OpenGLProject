/*#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

constexpr auto SCREEN_WIDTH = 640;
constexpr auto SCREEN_HEIGHT = 480;

void character_callback(GLFWwindow* window, unsigned int codepoint);
void charmods_callback(GLFWwindow* window, unsigned int codepoint, int mods);

int main() {
	GLFWwindow* window;

	if (!glfwInit()) return -1;

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	glfwSetCharModsCallback(window, charmods_callback);
	
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

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
}

void character_callback(GLFWwindow* window, unsigned int codepoint) {
	cout << codepoint << endl;
}

void charmods_callback(GLFWwindow* window, unsigned int codepoint, int mods) {
	cout << codepoint << " : " << mods << endl;
	if (mods == 1) cout << "shift key pressed aswell" << endl;
}*/