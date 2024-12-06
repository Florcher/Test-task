#include "ObjectFactory.h"

Object::ptr ObjectFactory::create(const int type) {

	if (type == Circle::Type())
		return std::make_shared<Circle>();

	if (type == Ellipse::Type())
		return std::make_shared<Ellipse>();

	if (type == Helix::Type())
		return std::make_shared<Helix>();

	throw std::exception();
}