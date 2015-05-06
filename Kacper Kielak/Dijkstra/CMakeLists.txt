
set(dijkstra_src Dijkstra.cpp main.cpp Structures.cpp)

set(CMAKE_CXX_FLAGS "-Wall -g")

add_executable(dijkstra ${dijkstra_src})
