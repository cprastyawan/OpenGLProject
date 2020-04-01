#include <GL/glew.h>
#include <GLFW/glfw3.h> 
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

void create_red_vao(GLuint& vao);
void create_dots_vao(GLuint& vao);
void Circlin(float radius, int a);
void counters();

float i = 0;
int counter = 0;

void setup_viewport(GLFWwindow* window)
{
	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-22, 22, -17, 17, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main() {
	if (!glfwInit()) {
		fprintf(stderr, "ERROR : could not open windows with GLFW3\n");
		glfwTerminate();
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Circle", NULL, NULL);
	if (!window) {
		fprintf(stderr, "ERROR : could not open windows with GLFW3\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	//start GLEW Exstension handler
	glewExperimental = GL_TRUE;
	glewInit();

	//get version info
	const GLubyte* renderer = glGetString(GL_RENDER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glfwSwapInterval(20);
	while (!glfwWindowShouldClose(window))
	{

		setup_viewport(window);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3ub(255, 255, 0);
		for (int i = 360; i >= 0; i--) {
			Circlin(3, i);
		}
		glPushMatrix();
		//glPopMatrix();

		glfwPollEvents();
		//put drawing
		glfwSwapBuffers(window);

	}
}


void Circlin(float radius, int a) {
	glBegin(GL_POLYGON);
	int dots = 360;
	int x_mid = 0;
	int y_mid = 0;
	int angle, i;

	glVertex2f(x_mid, y_mid);

	for (i = 0; i <= a; i++) {
		float angle = i * (2 * 3.14 / dots);
		float x = x_mid + radius * cos(angle);
		float y = y_mid + radius * sin(angle);
		glVertex2f(x, y);
	}
	glVertex2f(x_mid, y_mid);
	glEnd();
}