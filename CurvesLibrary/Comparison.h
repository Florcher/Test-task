#ifndef __COMPARISON_H_
#define __COMPARISON_H_
#include <iostream>

bool inline IsEqual(double x, double y, double epsilon = std::numeric_limits<double>::epsilon()) {
	return std::fabs(x - y) < epsilon;
}

bool inline Less(double x, double y, double epsilon = std::numeric_limits<double>::epsilon()) {
	return (-x + y) > epsilon;
}

bool inline LessOREqual(double x, double y, double epsilon = std::numeric_limits<double>::epsilon()) {
	return Less(x, y, epsilon) or IsEqual(x, y, epsilon);
}

#endif __COMPARISON_H_
