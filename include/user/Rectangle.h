#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Color {
	float red;
	float green;
	float blue;
	float alpha;

	bool operator==(const Color& other) const {
		return red == other.red && green == other.green 
			&& blue == other.blue && alpha == other.alpha;
	}
	bool operator!=(const Color&other) const {
		if (red != other.red || green != other.green || blue != other.blue || alpha != other.alpha) return true;
		else return false;
	}
};

struct Point {
	float x;
	float y;
};

class Rectangle {
public:
	Rectangle(Point p, Color c, float s);
	~Rectangle();

	Point point;
	Color color;
	float size;

	static glm::vec3 pos[4];
	static unsigned int sizeRect;

	static unsigned int indices[6];
	static unsigned int indicescount;

	bool hide;

	glm::mat4 Scale;
	glm::mat4 Position;
	glm::mat4 ZeroScale;

	Point Max;
	Point Min;
};