//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include <iostream>
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//
//const GLchar* vertexShaderSource ="#version 330 core\n"
//"layout (location = 0) in vec3 position;\n"
//"layout (location = 1) in vec3 color;\n"
//"out vec3 ourColor;\n"
//"uniform mat4 transform;\n"
//"void main()\n"
//"{\n"
//"gl_Position = transform * vec4(position, 1.0f);\n"
//"ourColor = color;\n"
//"}\0";
//
//const GLchar* fragmentShaderSource =  "#version 330 core\n"
//"in vec3 ourColor;\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"color = vec4(ourColor, 1.0f);\n"
//"}\n\0";////int main() {
//	glfwInit();//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);////	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Triangle", nullptr, nullptr);//	glfwMakeContextCurrent(window);//	glfwSetKeyCallback(window, key_callback);////	glewExperimental = GL_TRUE;////	glewInit();////	glViewport(0, 0, WIDTH, HEIGHT);////	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//	glCompileShader(vertexShader);////	GLint success;//	GLchar infoLog[512];////	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog <<
//			std::endl;
//	}
//	// Fragment shader
//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//	// Check for compile time errors
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog <<
//			std::endl;
//	}
//	// Link shaders
//	GLuint shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	// Check for linking errors
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//	// Set up vertex data (and buffer(s)) and attribute pointers
//	GLfloat vertices[] = {
//		// Positions // Colors
//		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Right
//		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // Bottom Left
//		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // Top
//	};
//	glm::mat4 trans;
//	trans = glm::rotate(trans, 90.0f, glm::vec3(0.0, 0.0, 1.0));
//	GLuint VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	// Position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	// Color attribute
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0); // Unbind VAO
//						  // Game loop
//	while (!glfwWindowShouldClose(window))
//	{
//		// Check if any events have been activiated (key pressed, mouse moved etc.) and call correspondingresponse functions
//		glfwPollEvents();
//		// Render
//		// Clear the colorbuffer
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		// Draw the triangle
//		glUseProgram(shaderProgram);
//		glm::mat4 transform;
//		//transform=glm::translate(transform, glm::vec3(0.5f,-0.5f,0.0f));
//		transform = glm::rotate(transform, 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
//		GLint transformLoc = glGetUniformLocation(shaderProgram, "transform");
//		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindVertexArray(0);
//		// Swap the screen buffers
//		glfwSwapBuffers(window);
//	}
//	// Properly de-allocate all resources once they've outlived their purpose
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	// Terminate GLFW, clearing any resources allocated by GLFW.
//	glfwTerminate();
//	return 0;
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}