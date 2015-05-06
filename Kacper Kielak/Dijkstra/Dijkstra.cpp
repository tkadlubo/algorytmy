#include "Dijkstra.h"
#include <iostream>

Dijkstra::Dijkstra(std::vector<Vertex>& _vertices, int _verticesNumber, int _start) :
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
        checkClosestVertex();

    return;
}

void Dijkstra::checkClosestVertex()
{
    Vertex& closestVertex = getClosestVertex();

    for(size_t i=0; i<closestVertex.neighbours.size(); i++)
    {
        Vertex& tempVertex = closestVertex.neighbours[i].neighbour;
        if(tempVertex.travelCost > closestVertex.travelCost + closestVertex.neighbours[i].travelCost)
        {
            tempVertex.travelCost = closestVertex.travelCost + closestVertex.neighbours[i].travelCost;
        }

    }
    closestVertex.visited = true;
    numberOfCheckedVertices++;

    return;
}

bool Dijkstra::isEnd()
{
    return numberOfCheckedVertices == verticesNumber;
}

Vertex& Dijkstra::getClosestVertex()
{
    int minTravelCost = INFINITY;
    int closestVertex;
    for(int i=0; i<verticesNumber; i++)
    {
        if(uncheckedVertices[i].isVisited())
            continue;

        if(uncheckedVertices[i].travelCost<minTravelCost)
        {
            minTravelCost = uncheckedVertices[i].travelCost;
            closestVertex = i;
        }
    }
    return uncheckedVertices[closestVertex];
}

Dijkstra::~Dijkstra()
{
}
