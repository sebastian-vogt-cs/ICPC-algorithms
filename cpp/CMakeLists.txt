project(ICPC-algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(floyd-warshall pathfinding/floyd_warshall.cpp)
add_executable(prefix-sum prefix_sum/prefix_sum.cpp)
add_executable(sqrt_decomposition sqrt_decomposition/sqrt_decomposition.cpp)