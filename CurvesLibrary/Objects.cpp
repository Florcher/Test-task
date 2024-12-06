#include "Objects.h"
#include "math.h"
#include "ObjectTypes.h"


//Throws exceptions, but it is safe here because circle doesn't allocate any resources.
Circle::Circle(const double radius)  {
	setRadius(radius); 
}

Point3D Circle::computePoint(const double param) const {
	Point3D point;

	point.x = mRadius * cos(param);
	point.y = mRadius * sin(param);
	point.z = 0;

	return point;
}

Vector3D Circle::computeDerivative(const double param) const {
	
	Vector3D vec;
	vec.x = -mRadius * sin(param);
	vec.y = mRadius * cos(param);
	vec.z = 0;

	return vec;
}

void Circle::setRadius(const double radius) {
	if (LessOREqual(radius, 0))
		throw std::exception();

	mRadius = radius;
}

double Circle::getRadius() const {
	return mRadius;
}

inline int Circle::Type() {
	return CircleType;
}

int Circle::getType() const {
	return Type();
}

//Throws exceptions, but it is safe here because ellipse doesn't allocate any resources.
Ellipse::Ellipse(const double majorSemiAxis, const double minorSemiAxis)  
{
	setMajorSemiAxis(majorSemiAxis);
	setMinorSemiAxes(minorSemiAxis);
}

Point3D Ellipse::computePoint(const double param) const {
	Point3D point;

	point.x = mMajorSemiAxis * cos(param);
	point.y = mMinorSemiAxis * sin(param);
	point.z = 0;

	return point;
}

Vector3D Ellipse::computeDerivative(const double param) const {
	
	Vector3D vec;
	vec.x = -mMajorSemiAxis * sin(param);
	vec.y = mMinorSemiAxis * cos(param);
	vec.z = 0;

	return vec;
}

void Ellipse::setMajorSemiAxis(const double majorSA) {
	if (LessOREqual(majorSA, 0))
		throw std::exception();

	mMajorSemiAxis = majorSA;
}

void Ellipse::setMinorSemiAxes(const double minorSA) {
	if (LessOREqual(minorSA, 0))
		throw std::exception();

	mMinorSemiAxis = minorSA;
}

double Ellipse::getMajorSemiAxes() const {
	return mMajorSemiAxis;
}

double Ellipse::getMinorSemiAxes() const {
	return mMinorSemiAxis;
}

int inline Ellipse::Type() {
	return EllipseType;
}

int Ellipse::getType() const {
	return Type();
}

//Throws exceptions, but it is safe here because helix doesn't allocate any resources.
Helix::Helix(const double paramA, const double paramB) 
{
	setParamA(paramA);
	setParamB(paramB);
}

Point3D Helix::computePoint(const double param) const {
	Point3D point;

	point.x = mParamA * cos(param);
	point.y = mParamA * sin(param);
	point.z = mParamB * param;

	return point;
}

Vector3D Helix::computeDerivative(const double param) const {

	Vector3D vec;
	vec.x = -mParamA * sin(param);
	vec.y = mParamB* cos(param);
	vec.z = mParamB;

	return vec;
}

void Helix::setParamA(const double paramA) {
	if (LessOREqual(paramA, 0))
		throw std::exception();

	mParamA = paramA;
}
void Helix::setParamB(const double paramB) {
	if (LessOREqual(paramB, 0))
		throw std::exception();

	mParamB = paramB;
}

double Helix::getParamA() const {
	return mParamA;
}

double Helix::getParamB() const {
	return mParamB;
}

inline int Helix::Type() {
	return HelixType;
}

int Helix::getType() const {
	return Type();
}