#ifndef __OBJECTS_H_
#define __OBJECTS_H_
#include "Header.h"
#include <iostream>
#include "Point3D.h"
#include "Vector3D.h"

class KERNEL_EXPORT Object {
public:
	Object() = default;
	Object(const int id);
	virtual ~Object() {};

	void setID(int id);
	int getID() const;

	virtual Point3D computePoint(const double param) const = 0;
	virtual Vector3D computeDerivative(const double param) const = 0;

	virtual int getType() const = 0;

	virtual void randomGenerate(const int maxParam) = 0;

	using ptr = std::shared_ptr<Object>;
private:
	int mId;
	int mTypeID;
};

class KERNEL_EXPORT Circle : public Object{
public:
	Circle() = default;
	Circle(const int id, const double radius);
	~Circle() {};

	Point3D computePoint(const double param) const override;
	Vector3D computeDerivative(const double param) const override;

	void setRadius(const double radius);
	double getRadius() const;

	inline static int Type();
	virtual int getType() const override;

	void randomGenerate(const int maxParam) override;

	using ptr = std::shared_ptr<Circle>;
private:
	double mRadius;
};

class KERNEL_EXPORT Ellipse : public Object{
public:
	Ellipse() = default;
	Ellipse(const int id, const double majorSemiAxis, const double minorSemiAxis);
	~Ellipse() {};

	Point3D computePoint(const double param) const override;
	Vector3D computeDerivative(const double param) const override;

	void setMajorSemiAxis(const double majorSA);
	void setMinorSemiAxes(const double minorSA);

	double getMajorSemiAxes() const;
	double getMinorSemiAxes() const;

	inline static int Type();
	virtual int getType() const override;

	void randomGenerate(const int maxParam) override;

	using ptr = std::shared_ptr<Ellipse>;
private:
	double mMajorSemiAxis;
	double mMinorSemiAxis;
};

class KERNEL_EXPORT Helix : public Object {
public:
	Helix() = default;
	Helix(const int id, const double paramA, const double paramB);
	~Helix() {};

	Point3D computePoint(const double param) const override;
	Vector3D computeDerivative(const double param) const override;

	void setParamA(const double paramA);
	void setParamB(const double paramB);

	double getParamA() const;
	double getParamB() const;

	inline static int Type();
	virtual int getType() const override;

	void randomGenerate(const int maxParam) override;

	using ptr = std::shared_ptr<Helix>;
private:
	double mParamA;
	double mParamB;
};





#endif __OBJECTS_H_
