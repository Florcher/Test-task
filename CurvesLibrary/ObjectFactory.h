#ifndef __OBJECTFACTORY_H_
#define __OBJECTFACTORY_H_
#include "Header.h"
#include "Objects.h"

struct KERNEL_EXPORT ObjectFactory {
	static Object::ptr create(const int type);
};

#endif
