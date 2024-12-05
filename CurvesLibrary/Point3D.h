#ifndef __POINT3D_H_
#define __POINT3D_H_
#include <iostream>
#include "Header.h"

struct KERNEL_EXPORT Point3D {

	friend std::ostream& operator<< (std::ostream& output, const Point3D& point);
	friend std::istream& operator>> (std::istream&, Point3D&);

	double x;
	double y;
	double z;

	using ptr = std::shared_ptr<Point3D>;
};




#endif __POINT3D_H_