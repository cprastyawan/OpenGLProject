#include "Rectangle.h"

unsigned int Rectangle::sizeRect = sizeof(glm::vec3) * 4;
unsigned int Rectangle::indicescount = 6;

glm::vec3 Rectangle::pos[4] = {
	glm::vec3(-1.0f, 1.0f, 0.0f),
	glm::vec3(-1.0f, -1.0f, 0.0f),
	glm::vec3(1.0f, -1.0f,0.0f),
	glm::vec3(1.0f, 1.0f, 0.0f)
};

unsigned int Rectangle::indices[6] = {
	0,1,2,
	2,3,0
};

Rectangle::Rectangle(Point p, Color c, float s) {
	point = p;
	color = c;
	size = s;

	Scale = glm::scale(glm::mat4(), glm::vec3(size, size, 1.0f));
	Position = glm::translate(glm::mat4(), glm::vec3(point.x, point.y, 0.0f));
	ZeroScale = glm::scale(glm::mat4(), glm::vec3(0.0f, 0.0f, 1.0f));
	hide = false;

	Max = { point.x + size, point.y + size };
	Min = { point.x - size, point.y - size };
}
Rectangle::~Rectangle() {

}