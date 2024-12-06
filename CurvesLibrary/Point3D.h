#ifndef __POINT3D_H_
#define __POINT3D_H_
#include <iostream>
#include "Header.h"

struct KERNEL_EXPORT Point3D {
	
	void print() const;

	double x;
	double y;
	double z;

	using ptr = std::shared_ptr<Point3D>;
};

#endif __POINT3D_H_