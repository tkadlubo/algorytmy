#include <vector>

#define INFINITY 2000000000

struct Vertice;

struct Neighbor
{
    Neighbor(Vertice& _neighbor, int _travelCost) :
        neighbor(_neighbor),
        travelCost(_travelCost)
    {}
    Vertice& neighbor;
    int travelCost;
};

struct Vertice
{
    std::vector<Neighbor> neighbors;
    int travelCost;//=INFINITY

    void reset()
    {
        this->travelCost = INFINITY;
        this->neighbors.clear();
    }

    bool isVisited() const
    {
        return this->travelCost != INFINITY;
    }
};
