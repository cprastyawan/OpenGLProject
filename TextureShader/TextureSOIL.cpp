//#include <iostream>
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include <soil/SOIL.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include "myshader.h"
//
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void create_texture(const char get_file[14], GLuint& texture);
//void triangle(GLuint& VAO, GLuint& VBO); //GLuint& EBO
//										 // Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello Triangle", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//	// Define the viewport dimensions
//	glViewport(0, 0, WIDTH, HEIGHT);
//	// Build and compile our shader program
//	Shader ourShader("vertex.vs", "fragment.frag");
//	// Set GL Array and handle with Shader Class
//	GLuint VAO, VBO;
//	triangle(VAO, VBO);
//	while (!glfwWindowShouldClose(window))
//	{
//		// Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
//			glfwPollEvents();
//		// Render
//		// Clear the color buffer
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		// Activate shader
//		ourShader.Use();
//		//Transformation
//		glm::mat4 model;
//		glm::mat4 view;
//		glm::mat4 projection;
//		model = glm::rotate(model, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
//		view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
//		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		// Get their uniform location
//		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
//		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//		// Pass them to the shaders
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		// Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		// Draw container
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
//void triangle(GLuint& VAO, GLuint& VBO) //GLuint &EBO
//{
//	GLfloat vertices[] = {
//		// Positions //Colors
//		0.5f,-0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //Left
//		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, //Right
//		0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f //Top
//	};
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	// glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	// Position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	//Color Attrib
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
//		sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0); // Unbind VAO
//}
//// Function that can create texture
//void create_texture(const char get_file[14], GLuint &texture) {
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
//		// Set our texture parameters
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	// Set texture filtering
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	// Load, create texture and generate mipmaps
//	int width, height;
//	unsigned char* image = SOIL_load_image(get_file, &width, &height, 0, SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE,
//		image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//	SOIL_free_image_data(image);
//	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}