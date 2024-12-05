#include "Objects.h"
#include <ctime>
#include <vector>
#include "ObjectFactory.h"
#include <algorithm>
#include "Point3D.h"

int main() {

	srand(time(0));

	std::cout << "Enter count of objects " << std::endl;

	int size;
	std::cin >> size;
	std::vector<Object::ptr> objects(size);

	ObjectFactory factory;
	for (int i = 0; i < size; ++i) {
		int min = 1;
		int max = 3;
		int type = rand() % (max - min + 1) + min;
		objects[i] = factory.getObject(type);
		objects[i]->setID(i + 1);
	}

	std::cout << "Enter max parameters value: " << std::endl;
	int maxValue;
	std::cin >> maxValue;

	for (int i = 0; i < objects.size(); ++i) {
		objects[i]->randomGenerate(maxValue);
	}

	for (int i = 0; i < objects.size(); i++) {
		const double Pi = 3.1415926535;
		const double t = Pi / 4;
		std::cout << "Curve " << objects[i]->getType() << std::endl;
		Point3D point = objects[i]->computePoint(t);
		std::cout << point << std::endl;
		Vector3D vec = objects[i]->computeDerivative(t);
		//std::cout << vec << std::endl;
	}

	std::vector<Circle::ptr> circles;
	for (int i = 0; i < size; ++i) {
		if (objects[i]->getType() == Circle::Type())
			circles.push_back(std::dynamic_pointer_cast<Circle>(objects[i]));
	}

	std::sort(circles.begin(), circles.end(), [](auto lhs, auto rhs)
		{
			return (*lhs).getRadius() < (*rhs).getRadius();
		}
	);
		
	for (int i = 0; i < circles.size(); ++i) {
		std::cout << circles[i]->getRadius() << std::endl;
	}

	double totalRadius = 0;
	for (int i = 0; i < circles.size(); ++i) {
		totalRadius += circles[i]->getRadius();
	}

	std::cout << "Total radius = " << totalRadius << std::endl;

	return 0;
}