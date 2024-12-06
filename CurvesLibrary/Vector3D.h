#ifndef __VECTOR3D_H_
#define __VECTOR3D_H_
#include "Header.h"
#include <iostream>

struct KERNEL_EXPORT Vector3D {

	void print() const;

	double x;
	double y;
	double z;

	using ptr = std::shared_ptr<Vector3D>;
};

#endif __VECTOR3D_H_
