#ifndef __OBJECTFACTORY_H_
#define __OBJECTFACTORY_H_
#include "Header.h"
#include "Objects.h"

struct KERNEL_EXPORT ObjectFactory {
	Object::ptr getObject(const int type);
};

#endif __OBJECTFACTORY_H_
