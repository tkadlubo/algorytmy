#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

#include "Structures.cpp"

class Dijkstra
{
   public:
        Dijkstra(std::vector<Vertex>& _vertices, int _verticesNumber, int _start);
        void writeTravelCost(int finish);
        ~Dijkstra();
    private:
        int verticesNumber;
        std::vector<Vertex>& uncheckedVertices;
        int start;
        int numberOfCheckedVertices;
        void countTravelCosts();
        void checkClosestVertex();
        bool isEnd();
        Vertex& getClosestVertex();

};

#endif
