project(ICPC-algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(floyd-warshall pathfinding/floyd-warshall.cpp)
add_executable(prefix-sum prefixsums/prefix-sum.cpp)