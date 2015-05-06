
set(dijkstra_src Dijkstra.cpp main.cpp Structures.cpp)

set(CMAKE_CXX_FLAGS "-Wall -g -std=c++11")

add_executable(dijkstra ${dijkstra_src})
