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

    void reset()
    {
        this->travelCost = INFINITY;
        this->neighbours.clear();
    }

    bool isVisited() const
    {
        return this->travelCost != INFINITY;
    }
};
