set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(public_headers Comparison.h
ObjectFactory.h
Objects.h
ObjectTypes.h
Point3D.h
Vector3D.h)

list(APPEND SOURCE_FILES
${public_headers}
ObjectFactory.cpp
Objects.cpp
Point3D.cpp
Vector3D.cpp)

include(GenerateExportHeader)

add_library(CurvesKernel ${SOURCE_FILES})

target_include_directories(CurvesKernel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

generate_export_header(CurvesKernel)