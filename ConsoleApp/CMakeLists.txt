list(APPEND SOURCE_FILES
main.cpp)

add_executable(consoleApp ${SOURCE_FILES})
target_link_libraries(consoleApp CurvesKernel)