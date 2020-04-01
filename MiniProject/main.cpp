#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <user/IndexBuffer.h>
#include <user/Renderer.h>
#include <random>
#include <ctime>
#include <user/VertexArray.h>
#include <user/VertexBuffer.h>
#include <user/Shader.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <user/VertexBufferLayout.h>
#include <user/Rectangle.h>
#include <EasyBMP/EasyBMP.h>
#include <user/text2D.hpp>

#define WIDTH 640
#define HEIGHT 480

std::vector<Point> loadbmp(const char* filename);

Color Red = { 1.0f, 0.0f, 0.0f, 1.0f };
Color Green = { 0.0f, 1.0f, 0.0f, 1.0f };
Color Blue = { 0.0f, 0.0f, 1.0f, 1.0f };
Color Yellow = { 1.0f, 1.0f, 0.0f, 1.0f };
Color Orange = { 1.0f, 127.0f / 255.0f, 0.0f, 1.0f };
Color Violet = { 75.0f / 255.0f, 0.0f, 130.0f / 255.0f, 1.0f };
Color Brown = { 126.0f / 255.0f, 46.0f / 255.0f, 31.0f / 255.0f, 1.0f };
Color Pink = { 248.0f / 255.0f, 24.0f / 255.0f, 148.0f / 255.0f, 1.0f };
Color White = { 1.0f,1.0f,1.0f,1.0f };

void errorMessage(std::string text);
int randomGenerator(int min, int max);

static double xpos, ypos;
static Color colorPick;
Rectangle initRect(Point{ WIDTH / 2, HEIGHT / 2 }, Color{ 0.0f, 0.0f, 0.0f, 0.0f }, 0.0f);
std::vector<Rectangle> rect;
Color selectedColor;
static unsigned int score;
static unsigned int level;
static unsigned int countTrueRectangle;

Color generateRandomColor();	//Fungsi untuk menghasilkan warna secara acak
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods); //Fungsi callback mouse
std::vector<Rectangle> generateRectangle(int count, Color colorChoose); //Fungsi untuk menghasilkan persegi
void clearRectangle(std::vector<Rectangle> &rect); //Fungsi untuk menghapus semua persegi
void start(std::vector<Rectangle> &rect, Color &, unsigned int &level); //fungsi untuk memulai permainan
void levelUp(std::vector <Rectangle> &rect, unsigned int &level, Color &buffer, unsigned int &score); //fungsi untuk naik level
void scoreUp(unsigned int &score); //Fungsi untuk skor
void gameOver(unsigned int &score, std::vector<Rectangle> &rect, Color &buffer); //Fungsi untuk kalah
void restartGame(unsigned int &score, std::vector<Rectangle>& rect, Color &buffer);	//Fungsi untuk mengulangi permainan
unsigned int checkTrueRectangle(Color c, std::vector<Rectangle> rect);	//Fungsi untuk mengecek apakah persegi masih ada yang benar atau tidak
const char* printColor(Color c); //Fungsi untuk mencetak nama dari warna

int main() {
	srand((unsigned)time(NULL));
	
	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (!glfwInit()) errorMessage("glfwInit() error!\n");

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Tebak Warna", NULL, NULL);
	if (!window) errorMessage("glewInit() error!\n");

	glfwMakeContextCurrent(window);

	glfwSetMouseButtonCallback(window, mouseButtonCallback);

	if (glewInit() != GLEW_OK) errorMessage("glewInit() error!\n");

	glm::mat4 Projection = glm::ortho(0.0f, (float)WIDTH, (float)HEIGHT, 0.0f, -1.0f, 1.0f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 MVP = Projection * View;

	printf("Selamat datang dalam permainan tebak warna!!!\n");
	printf("Tekan Y untuk memulai permainan...\n");
	printf("Tekan Esc untuk keluar...\n");
	bool next = false;

	std::vector<Point> bmp = loadbmp("no1.bmp");
	Rectangle anim(Point{ 0.0f,0.0f }, Color{ 0.0f,0.0f,0.0f,0.0f }, 2.0f);
	glfwSwapInterval(3);

	//char *text = (char*)"Test123";
	initText2D("../res/font/Holstein.DDS");

	while (!next) {
		VertexArray va;
		VertexBuffer vb(initRect.pos, initRect.sizeRect);
		VertexBufferLayout layout;

		layout.Push<float>(3);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(initRect.indices, initRect.indicescount);

		Shader shader("res/shaders/Basic.shader");

		shader.Bind();

		va.Unbind();

		vb.Unbind();

		ib.Unbind();

		shader.Unbind();

		Renderer renderer;

		if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) next = true;
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) exit(1);

		for (int i = 0; i < bmp.size(); i++) {
			anim.color = generateRandomColor();
			anim.Position = glm::translate(glm::mat4(), glm::vec3(2 * bmp.at(i).x, 2 * bmp.at(i).y, 0.0f));
		/*	anim = Rectangle(bmp.at(i), generateRandomColor(), 1.0f);*/
			renderer.AddRectangle(anim, shader, MVP);
			renderer.Draw(va, ib, shader);
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	system("cls");
	glfwSwapInterval(1);
	start(rect, selectedColor, level);

	while (!glfwWindowShouldClose(window)) {

		VertexArray va;
		VertexBuffer vb(initRect.pos, initRect.sizeRect);
		VertexBufferLayout layout;

		layout.Push<float>(3);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(initRect.indices, initRect.indicescount);

		Shader shader("res/shaders/Basic.shader");

		shader.Bind();

		va.Unbind();

		vb.Unbind();

		ib.Unbind();

		shader.Unbind();

		Renderer renderer;


		renderer.Clear();
		shader.Bind();
		va.Bind();

		vb.Bind();

		ib.Bind();
		renderer.AddRectangle(initRect, shader, MVP);
		renderer.Draw(va, ib, shader);

		for (int i = 0; i < rect.size(); i++) {
			renderer.AddRectangle(rect.at(i), shader, MVP);
			renderer.Draw(va, ib, shader);
		}

		std::string text = "Score: " + std::to_string(score) + "   Warna: " + printColor(selectedColor);
		printText2D(text, 0, HEIGHT + 85, 30);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	cleanupText2D();
}

inline void errorMessage(std::string text) {
	std::cout << text;
	system("pause");
	exit(-1);
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		glfwGetCursorPos(window, &xpos, &ypos);
		glReadPixels(xpos, -ypos + HEIGHT, 1, 1, GL_RGBA, GL_FLOAT, &colorPick);
		for (int i = 0; i < rect.size(); i++) {
			if ((xpos <= rect.at(i).Max.x && xpos >= rect.at(i).Min.x) && (ypos <= rect.at(i).Max.y && ypos >= rect.at(i).Min.y)
				&& rect.at(i).color == selectedColor) {
				rect.erase(rect.begin() + i);
				scoreUp(score);
				if (checkTrueRectangle(selectedColor, rect) == 0) levelUp(rect, level, selectedColor, score);
			}
			else if ((xpos <= rect.at(i).Max.x && xpos >= rect.at(i).Min.x) && (ypos <= rect.at(i).Max.y && ypos >= rect.at(i).Min.y)
				&& rect.at(i).color != selectedColor)
				gameOver(score, rect, selectedColor);

		}
	}
}

int randomGenerator(int min, int max) {
	return rand() % max + min;
}

std::vector<Rectangle> generateRectangle(int count, Color colorChoose) {

	std::vector<Rectangle> temp;

	for (int i = 0; i < count; i++) {
		Color c;
		if (i == 0) c = colorChoose;
		else c = generateRandomColor();

		Point point;
		//if (i < count / 2) {
		//	point.x = (float)randomGenerator(150 / count, WIDTH - 150 / count);
		//	point.y = (float)randomGenerator(150 / count, HEIGHT - 150 / count);
		//}
		//else {
		//	point.x = (float)randomGenerator(0, WIDTH - 10);
		//	point.y = (float)randomGenerator(0, HEIGHT - 10);
		//}
		point.x = (float)randomGenerator(0, WIDTH);
		point.y = (float)randomGenerator(0, HEIGHT);
		temp.push_back(Rectangle(point, c, 200 / count));
	}
	return temp;
}

void clearRectangle(std::vector<Rectangle> &rect) {
	rect.clear();
}

void start(std::vector<Rectangle> &rect, Color &buffer, unsigned int &level) {
	printf("Permainan dimulai!\n");
	level = 1;
	int chooseColor = randomGenerator(1, 3);
	buffer = generateRandomColor();
	rect = generateRectangle(level, buffer);
	printf("Warna yang dipilih: %s\n", printColor(buffer));
}

void levelUp(std::vector<Rectangle> &rect, unsigned int &level, Color &buffer, unsigned int &score) {
	printf("Skor sementara: %d\n", score);
	rect.clear();
	level += 1;
	buffer = generateRandomColor();
	rect = generateRectangle(level, buffer);
	printf("\n\n");
	printf("Warna yang dipilih: %s\n", printColor(buffer));
}

Color generateRandomColor() {
	int x = randomGenerator(1, 9);
	if (x == 1) return Red;
	else if (x == 2) return Green;
	else if (x == 3) return Blue;
	else if (x == 4) return Orange;
	else if (x == 5) return Yellow;
	else if (x == 6) return Violet;
	else if (x == 7) return Brown;
	else if (x == 8) return Pink;
	else if (x == 9) return White;
}

void scoreUp(unsigned int &score) {
	score++;
}
void gameOver(unsigned int &score, std::vector<Rectangle>& rect, Color &buffer) {
	char input;
	printf("Anda salah menekan warna!\n");
	printf("Score anda: %d\n", score);
	printf("Masukkan y untuk main lagi: ");
	std::cin >> input;
	if (input == 'y' || input == 'Y') restartGame(score, rect, buffer);
	else exit(1);
}

void restartGame(unsigned int &score, std::vector<Rectangle>& rect, Color &buffer) {
	rect.clear();	
	score = 0;
	system("pause");
	start(rect, buffer, level);
}

unsigned int checkTrueRectangle(Color c, std::vector<Rectangle> rect) {
	int count = 0;
	for (int i = 0; i < rect.size(); i++) {
		if (rect.at(i).color == c) count++;
		else continue;
	}
	return count;
}

const char* printColor(Color c) {
	if (c == Red) return "Merah";
	else if (c == Green) return "Hijau";
	else if (c == Blue) return "Biru";
	else if (c == Orange) return "Oranye";
	else if (c == Yellow) return "Kuning";
	else if (c == Violet) return "Ungu";
	else if (c == Brown) return "Coklat";
	else if (c == Pink) return "Merah Muda";
	else if (c == White) return "Putih";
	else return "Warna tidak terdaftar";
}

std::vector<Point> loadbmp(const char* filename) {
	BMP bmp;
	bmp.ReadFromFile(filename);
	std::vector<Point> buf;
	for (int i = 0; i < bmp.TellHeight(); i++) {
		for (int j = 0; j < bmp.TellWidth(); j++) {
			if (bmp(j, i)->Red == 0) buf.push_back(Point{ (float)j, (float)i });
		}
	}
	return buf;
}
