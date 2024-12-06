#ifndef __UTILS_H_
#define __UTILS_H_
#include "Header.h"
#include <limits>
#include <cmath>

bool inline IsEqual(double x, double y, double epsilon = std::numeric_limits<double>::epsilon()) {
	return std::fabs(x - y) < epsilon;
}

bool inline Less(double x, double y, double epsilon = std::numeric_limits<double>::epsilon()) {
	return (-x + y) > epsilon;
}

bool inline LessOREqual(double x, double y, double epsilon = std::numeric_limits<double>::epsilon()) {
	return Less(x, y, epsilon) || IsEqual(x, y, epsilon);
}

inline int rndInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}

inline double rndDouble(double max) {
	return static_cast<double>((rand()) / RAND_MAX * max);
}

struct KERNEL_EXPORT Point3D {

	double x;
	double y;
	double z;
};

struct KERNEL_EXPORT Vector3D {

	double x;
	double y;
	double z;
};

#endif 
