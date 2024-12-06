#include "Vector3D.h"

/*std::ostream& operator<< (std::ostream& output, const Vector3D& vec) {

	output << "Start point" << vec.mStart;
	output << "End point" << vec.mEnd;

	return output;
}

std::istream& operator>> (std::istream& input, Vector3D& vec) {

	input >> vec.mStart;
	input >> vec.mEnd;

	return input;
}
*/

void Vector3D::print() const {
	std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}