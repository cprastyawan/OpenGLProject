/*#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <cstdio>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;


void drawTriangle(GLFWwindow *window) {
	float points[] = {
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
	};

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
		"	frag_colour = vec4(161, 155, 0, 1);"
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

	glUseProgram(shader_programme);
	glBindVertexArray(vao);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES,0,10);
	glfwPollEvents();
	glfwSwapBuffers(window);

}

int main() {
	GLFWwindow* window;

	vec4 vec(5.0f, 2.0f, 0.0f, 1.0f);
	mat4 trans;
	trans = scale(trans, glm::vec3(0.0, 0.0, 1.0));
	vec = trans * vec;
	printf("%f\n", vec.x);
	printf("%f\n", vec.y);
	printf("%f\n", vec.z);

	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return -1;
	}

	window = glfwCreateWindow(640, 480, "Primitive Drawing", NULL, NULL);

	if (!window) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);

	printf("Renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(window)) {

		drawTriangle(window);
	}
	glfwTerminate();
}*/