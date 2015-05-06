#include "Dijkstra.h"
#include <iostream>

Dijkstra::Dijkstra(Vertice* vertices, int verticesNumber, int start)
{
    this->uncheckedVertices = vertices;
    this->checkedVertices = new Vertice[verticesNumber];
    this->verticesNumber = verticesNumber;
    this->start = start;
    this->numberOfCheckedVertices = 0;
    countTravelCosts();
}

void Dijkstra::writeTravelCost(int finish)
{
    if(uncheckedVertices[finish].isReseted())
        std::cout << checkedVertices[finish].travelCost << std::endl;
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
    int ordinalOfClosestVertice = getOrdinalOfClosestVertice();
    Vertice closestVertice = uncheckedVertices[ordinalOfClosestVertice];

    for(size_t i=0; i<closestVertice.neighbors.size(); i++)
    {
        Vertice tempVertice = uncheckedVertices[closestVertice.neighbors[i].ordinal];
        if(!tempVertice.isReseted() && tempVertice.travelCost > closestVertice.travelCost + closestVertice.neighbors[i].travelCost)
        {
            tempVertice.pathToStart = ordinalOfClosestVertice;
            tempVertice.travelCost = closestVertice.travelCost + closestVertice.neighbors[i].travelCost;
        }

        uncheckedVertices[closestVertice.neighbors[i].ordinal] = tempVertice;
    }

    checkedVertices[ordinalOfClosestVertice] = closestVertice;
    uncheckedVertices[ordinalOfClosestVertice].reset();
    numberOfCheckedVertices++;

    return;
}

bool Dijkstra::isEnd()
{
    if(numberOfCheckedVertices<verticesNumber)
        return false;

    return true;
}

int Dijkstra::getOrdinalOfClosestVertice()
{
    int minTravelCost = INFINITY;
    int closestVertice = UNDEFINED;
    for(int i=0; i<verticesNumber; i++)
    {
        if(uncheckedVertices[i].travelCost<minTravelCost)
        {
            minTravelCost = uncheckedVertices[i].travelCost;
            closestVertice = i;
        }
    }
    return closestVertice;
}

Dijkstra::~Dijkstra()
{
    delete checkedVertices;
    delete uncheckedVertices;
}
