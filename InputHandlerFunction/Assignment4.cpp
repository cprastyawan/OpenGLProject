#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
using namespace std;

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main() {
	GLFWwindow* window;

	if (!glfwInit()) return -1;

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetKeyCallback(window, keyCallback);


	if (!window) {
		glfwTerminate();
		return -1;
	}
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		cout << "Mouse klik kanan!" << endl;
		glfwMakeContextCurrent(window);
		float points[] = {
			0.0f, 0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f
		};

		glewExperimental = GL_TRUE;
		glewInit();

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		GLuint vbo;
		glGenBuffers(1, &vbo);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

		GLuint vao = 0;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		const char* vertex_shader = "#version 400\n"
			"in vec3 vp;"
			"void main(){"
			"	gl_Position = vec4(vp, 1.0);"
			"}";

		const char* fragment_shader =
			"#version 400\n"
			"out vec4 frag_colour;"
			"void main(){"
			"	frag_colour = vec4(0.5, 0.25, 0.1, 1);"
			"}";

		GLuint vs = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vs, 1, &vertex_shader, NULL);
		glCompileShader(vs);
		GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fs, 1, &fragment_shader, NULL);
		glCompileShader(fs);

		GLuint shader_programme = glCreateProgram();
		glAttachShader(shader_programme, fs);
		glAttachShader(shader_programme, vs);
		glLinkProgram(shader_programme);

		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glUseProgram(shader_programme);
			glBindVertexArray(vao);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glPointSize(20.0);
			glfwPollEvents();
			glfwSwapBuffers(window);
		}
	}
}
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		cout << "Spasi ditekan!" << endl;
		glfwMakeContextCurrent(window);
		float points[] = {
			0.0f, 0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f
		};

		glewExperimental = GL_TRUE;
		glewInit();

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		GLuint vbo;
		glGenBuffers(1, &vbo);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

		GLuint vao = 0;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		const char* vertex_shader = "#version 400\n"
			"in vec3 vp;"
			"void main(){"
			"	gl_Position = vec4(vp, 1.0);"
			"}";

		const char* fragment_shader =
			"#version 400\n"
			"out vec4 frag_colour;"
			"void main(){"
			"	frag_colour = vec4(0.1, 0.75, 0.4, 1);"
			"}";

		GLuint vs = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vs, 1, &vertex_shader, NULL);
		glCompileShader(vs);
		GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fs, 1, &fragment_shader, NULL);
		glCompileShader(fs);

		GLuint shader_programme = glCreateProgram();
		glAttachShader(shader_programme, fs);
		glAttachShader(shader_programme, vs);
		glLinkProgram(shader_programme);

		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glUseProgram(shader_programme);
			glBindVertexArray(vao);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glPointSize(20.0);
			glfwPollEvents();
			glfwSwapBuffers(window);
		}
	}
}
