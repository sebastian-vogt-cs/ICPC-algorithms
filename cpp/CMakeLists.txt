project(ICPC-algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(floyd-warshall pathfinding/floyd_warshall.cpp)
add_executable(prefix-sum prefix_sum/prefix_sum.cpp)
add_executable(sqrt_decomposition sqrt_decomposition/sqrt_decomposition.cpp)
add_executable(segment_tree segment_tree/segment_tree.cpp)
add_executable(lowest_common_ancestor lowest_common_ancestor/lowest_common_ancestor.cpp)