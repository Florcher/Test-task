
#ifndef CURVESKERNEL_EXPORT_H
#define CURVESKERNEL_EXPORT_H

#ifdef CURVESKERNEL_STATIC_DEFINE
#  define CURVESKERNEL_EXPORT
#  define CURVESKERNEL_NO_EXPORT
#else
#  ifndef CURVESKERNEL_EXPORT
#    ifdef CurvesKernel_EXPORTS
        /* We are building this library */
#      define CURVESKERNEL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define CURVESKERNEL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef CURVESKERNEL_NO_EXPORT
#    define CURVESKERNEL_NO_EXPORT 
#  endif
#endif

#ifndef CURVESKERNEL_DEPRECATED
#  define CURVESKERNEL_DEPRECATED __declspec(deprecated)
#endif

#ifndef CURVESKERNEL_DEPRECATED_EXPORT
#  define CURVESKERNEL_DEPRECATED_EXPORT CURVESKERNEL_EXPORT CURVESKERNEL_DEPRECATED
#endif

#ifndef CURVESKERNEL_DEPRECATED_NO_EXPORT
#  define CURVESKERNEL_DEPRECATED_NO_EXPORT CURVESKERNEL_NO_EXPORT CURVESKERNEL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef CURVESKERNEL_NO_DEPRECATED
#    define CURVESKERNEL_NO_DEPRECATED
#  endif
#endif

#endif /* CURVESKERNEL_EXPORT_H */
