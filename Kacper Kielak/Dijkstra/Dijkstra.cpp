#include "Dijkstra.h"
#include <iostream>

Dijkstra::Dijkstra(std::vector<Vertice>& _vertices, int _verticesNumber, int _start) :
    verticesNumber(_verticesNumber),
    uncheckedVertices(_vertices),
    start(_start),
    numberOfCheckedVertices(0)
{
    countTravelCosts();
}

void Dijkstra::writeTravelCost(int finish)
{
    if(uncheckedVertices[finish].isVisited())
        std::cout << uncheckedVertices[finish].travelCost << std::endl;
    else
        std::cout << "NO" << std::endl;

    return;
}

void Dijkstra::countTravelCosts()
{
    while(!isEnd())
        checkClosestVertice();

    return;
}

void Dijkstra::checkClosestVertice()
{
    Vertice& closestVertice = getClosestVertice();

    for(size_t i=0; i<closestVertice.neighbors.size(); i++)
    {
        Vertice& tempVertice = closestVertice.neighbors[i].neighbor;
        if(tempVertice.travelCost > closestVertice.travelCost + closestVertice.neighbors[i].travelCost)
        {
            tempVertice.travelCost = closestVertice.travelCost + closestVertice.neighbors[i].travelCost;
        }

    }

    numberOfCheckedVertices++;

    return;
}

bool Dijkstra::isEnd()
{
    return numberOfCheckedVertices == verticesNumber;
}

Vertice& Dijkstra::getClosestVertice()
{
    int minTravelCost = INFINITY;
    int closestVertice;
    for(int i=0; i<verticesNumber; i++)
    {
        if(uncheckedVertices[i].travelCost<minTravelCost)
        {
            minTravelCost = uncheckedVertices[i].travelCost;
            closestVertice = i;
        }
    }
    return uncheckedVertices[closestVertice];
}

Dijkstra::~Dijkstra()
{
}
