#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Color {
	float red;
	float green;
	float blue;
	float alpha;
};

struct Point {
	float x;
	float y;
};

class Object {
public:
	Point getPoint();
	Color getColor();
	glm::mat4 getScale();
protected:
	Point point;
	Color color;
	glm::mat4 scale;

};