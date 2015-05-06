#include <vector>
#include <cstdint>

#define INFINITY INT32_MAX

struct Vertex;

struct Neighbour
{
    Neighbour(Vertex& _neighbour, int _travelCost) :
        neighbour(_neighbour),
        travelCost(_travelCost)
    {}
    Vertex& neighbour;
    int travelCost;
};

struct Vertex
{
    std::vector<Neighbour> neighbours;
    int travelCost;//=INFINITY
    bool visited;

    void reset()
    {
        travelCost = INFINITY;
        neighbours.clear();
        visited = false;
    }

    bool isVisited() const
    {
        return visited;
    }
};
