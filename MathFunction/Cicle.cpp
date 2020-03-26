//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <stdio.h>
//using namespace glm;
//
//void create_red_vao(GLuint& vao);
//void create_dots_vao(GLuint& vao);
//void Circlin(float radius, int a);
//static int ulang = 0;
//float i = 0;
//
//void setup_viewport(GLFWwindow* window) {
//	float ratio;
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	ratio = width / (float)height;
//	glViewport(0, 0, width, height);
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-22, 22, -17, 17, 1.f, -1.f);
//	glLoadIdentity();
//}
//
//int main() {
//	if (!glfwInit()) {
//		fprintf(stderr, "ERROR: Could not start GLFW3");
//		return -1;
//	}
//
//	GLFWwindow* window = glfwCreateWindow(640, 480, "Circle", NULL, NULL);
//	if (!window) {
//		fprintf(stderr, "ERROR: could not open window with glfw3\n");
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//	glewExperimental = GL_TRUE;
//	if (glewInit()) {
//		fprintf(stderr, "ERROR: could not initialize glew\n");
//		return -1;
//	}
//
//	const GLubyte* renderer = glGetString(GL_RENDERER);
//	const GLubyte* version = glGetString(GL_VERSION);
//
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LESS);
//
//	while (!glfwWindowShouldClose(window)) {
//		setup_viewport(window);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glColor3ub(255, 255, 0);
//		Circlin(0.1, 360);
//		glPushMatrix();
//
//		glfwPollEvents();
//		glfwSwapBuffers(window);
//	}
//}
//
//void Circlin(float radius, int a) {
//	glBegin(GL_POLYGON);
//	int dots = 360;
//	int x_mid = 0;
//	int y_mid = 0;
//	int angle, i;
//
//	glVertex2f(x_mid, y_mid);
//	for (i = 0; i <= a + 1; i++) {
//		float angle = i * (2 * 3.14 / dots);
//		float x = x_mid + radius * cos(angle);
//		float y = y_mid + radius * sin(angle);
//		if (ulang <=360) printf("derajat ke : %d	 angle: %f, x: %f, y: %f\n", ulang, angle/3.14 , x, y);
//		ulang++;
//		glVertex2f(x, y);
//	}
//
//	glVertex2f(x_mid, y_mid);
//	glEnd();
//}