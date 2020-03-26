#include "Triangle.h"

unsigned int Triangle::sizeTriangle = sizeof(glm::vec3) * 3;
unsigned int Triangle::indicescount = 3;

glm::vec3 Triangle::pos[3] = {
	glm::vec3(1.0f, 1.0f, 0.0f),
	glm::vec3(-2.0f, -1.0f, 0.0f),
	glm::vec3(2.0f, -1.0f, 0.0f),
};

unsigned int Triangle::indices[3] = {
	2,1,0
};

Triangle::Triangle(Point p, Color c, float s) {
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
Triangle::~Triangle() {

}