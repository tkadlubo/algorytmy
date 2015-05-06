#include "Dijkstra.h"
#include <iostream>


std::vector<Vertex> initializeVertices(int verticesNumber, int edgesNumber)
{
    std::vector<Vertex> vertices;
    vertices.resize(verticesNumber);

    for(int i=0; i<verticesNumber; i++)
        vertices[i].reset();

    for(int i=0; i<edgesNumber; i++)
    {
        int travelCost, vertex1, vertex2;
        std::cin >> vertex1 >> vertex2 >> travelCost;
        Neighbour tempNeighbour1(vertices[vertex2 - 1], travelCost);
        Neighbour tempNeighbour2(vertices[vertex1 - 1], travelCost);

        vertices[vertex1-1].neighbours.push_back(tempNeighbour1);
        vertices[vertex2-1].neighbours.push_back(tempNeighbour2);
    }
    return std::move(vertices);
}

int main()
{
    int testsNumber;
    std::cin >> testsNumber;
    int verticesNumber, edgesNumber;
    int start, finish;
    for(int i=0; i<testsNumber; i++)
    {
        std::cin >> verticesNumber >> edgesNumber;

        std::vector<Vertex> vertices = initializeVertices(verticesNumber, edgesNumber);

        std::cin >> start >> finish;
        start--; //
        finish--;// coumputer counts from 0, not from 1
        vertices[start].travelCost = 0;

        Dijkstra dijkstra(vertices, verticesNumber, start);
        dijkstra.writeTravelCost(finish);
    }
    return 0;
}
