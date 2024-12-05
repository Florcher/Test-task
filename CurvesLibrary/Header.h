#ifndef __HEADER_H_
#define __HEADER_H_

#ifndef KERNEL_EXPORT
#define KERNEL_EXPORT __declspec(dllexport)
#else 
#define KERNEL_EXPORT __declspec(dllimport)
#endif


#endif __HEADER_H_