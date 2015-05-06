#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

#include "Structures.cpp"

class Dijkstra
{
   public:
        Dijkstra(std::vector<Vertice>& _vertices, int _verticesNumber, int _start);
        void writeTravelCost(int finish);
        ~Dijkstra();
    private:
        int verticesNumber;
        std::vector<Vertice> checkedVertices;
        std::vector<Vertice>& uncheckedVertices;
        int start;
        int numberOfCheckedVertices;
        void countTravelCosts();
        void checkClosestVertice();
        bool isEnd();
        int getOrdinalOfClosestVertice();

};

#endif
