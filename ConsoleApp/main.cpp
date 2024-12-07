#include "Objects.h"
#include <ctime>
#include <vector>
#include "ObjectFactory.h"
#include <algorithm>
#include "Utils.h"
#include <memory>
#include <iostream>


template <class T>
void print(T const& val) {
	std::cout << "(" << val.x << ", " << val.y << ", " << val.z << ")" << std::endl;
}

void fillObject(Object::ptr obj, double maxValue) {
	if (obj->getType() == Circle::Type()) {
		auto circle = std::static_pointer_cast<Circle>(obj);
		circle->setRadius(rndDouble(maxValue));
	}
	else if (obj->getType() == Ellipse::Type()) {
		auto ellipse = std::static_pointer_cast<Ellipse>(obj);
		ellipse->setMajorSemiAxis(rndDouble(maxValue));
		ellipse->setMinorSemiAxes(rndDouble(maxValue));
	}
	else if (obj->getType() == Helix::Type()) {
		auto helix = std::static_pointer_cast<Helix>(obj);
		helix->setParamA(rndDouble(maxValue));
		helix->setParamB(rndDouble(maxValue));
	}
}

std::vector<Object::ptr> createObjects(int size, double maxvalue) {

	std::vector<Object::ptr> objects(size);

	for (auto& obj : objects) {
		obj = ObjectFactory::create(rndInt(1,3));
		fillObject(obj, maxvalue);
	}
	return objects;
}

constexpr double PI = 3.1415926535;
constexpr double PI4 = PI / 4;

int main() {

	srand(time(0));

	std::cout << "Enter count of objects " << std::endl;

	int size;
	std::cin >> size;
	
	std::cout << "Enter max parameters value: " << std::endl;
	double maxValue;
	std::cin >> maxValue;

	auto objects = createObjects(size, maxValue);

	for (auto& obj : objects) {
		std::cout << "Curve type " << obj->getType() << std::endl;
		std::cout << "Point coordinate: ";
		Point3D point = obj->computePoint(PI4);
		print(point);
		std::cout << "Derivative coordinate: ";
		Vector3D vec = obj->computeDerivative(PI4);
		print(vec);
		std::cout << std::endl;
	}

	std::vector<Circle::ptr> circles;
	for (auto& obj : objects) {
		if (obj->getType() == Circle::Type())
			circles.push_back(std::static_pointer_cast<Circle>(obj));
	}

	std::sort(circles.begin(), circles.end(), [](auto& lhs, auto& rhs)
		{
			return Less(lhs->getRadius(), rhs->getRadius());
		}
	);
		
	for (auto& circle : circles) {
		std::cout << circle->getRadius() << std::endl;
	}

	double totalRadius = 0;
	for (auto& circle : circles) {
		totalRadius += circle->getRadius();
	}

	std::cout << "Total radius = " << totalRadius << std::endl;
	
	return 0;
}