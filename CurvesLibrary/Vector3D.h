#ifndef __VECTOR3D_H_
#define __VECTOR3D_H_
#include "Header.h"
#include "Point3D.h"

struct KERNEL_EXPORT Vector3D {

	friend std::ostream& operator<< (std::ostream&, const Vector3D&);
	friend std::istream& operator>> (std::istream&, Vector3D&);

	Point3D mStart;
	Point3D mEnd;

	using ptr = std::shared_ptr<Vector3D>;
};


#endif __VECTOR3D_H_
