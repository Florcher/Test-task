#include "Point3D.h"
#include <iostream>

std::ostream& operator<< (std::ostream& output, const Point3D& point) {

	output << "(" << point.x << ", " << point.y << ", " << point.z << ")" << std::endl;

	return output;
}

std::istream& operator>> (std::istream& input, Point3D& point) {

	input >> point.x;
	input >> point.y;
	input >> point.z;

	return input;
}