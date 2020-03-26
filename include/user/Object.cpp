#include "Object.h"

Point Object::getPoint()
{
	return Point(point);
}

Color Object::getColor()
{
	return Color(color);
}

glm::mat4 Object::getScale()
{
	return scale;
}
