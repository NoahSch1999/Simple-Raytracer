cmake_minimum_required (VERSION 3.20)

project (SimpleRaytracer VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable (SimpleRaytracer
	"main.cpp" 
	"SimpleRaytracer.h"
	"src/Matrix.cpp"
	"src/OBB.cpp"
	"src/Plane.cpp"
	"src/Ray.cpp"
	"src/Shape.cpp"
	"src/Sphere.cpp"
	"src/Triangle.cpp"
	"src/Vector3D.cpp"
)

target_include_directories(SimpleRaytracer
	PUBLIC ${PROJECT_SOURCE_DIR}src/
)