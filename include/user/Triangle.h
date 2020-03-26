#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Rectangle.h"

class Triangle {
public:
	Triangle(Point p, Color c, float s);
	~Triangle();

	Point point;
	Color color;
	float size;

	static glm::vec3 pos[3];
	static unsigned int sizeTriangle;

	static unsigned int indices[3];
	static unsigned int indicescount;

	bool hide;

	glm::mat4 Scale;
	glm::mat4 Position;
	glm::mat4 ZeroScale;

	Point Max;
	Point Min;
};