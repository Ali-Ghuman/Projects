#ifndef GRAPH_H
#define GRAPH_H

#include "heap.h"
#include "hash.h"
#include <list>  

class Graph
{
private:
    class Node
    {
    public: 

        class Edge
        {
        public: 
            int weight;
            Node* destVertex;

            Edge(int weight, Node* destination): weight{weight}, destVertex{destination} {}
        };

        std::string id;
        int pathLength;
        std::list<Edge> adjacencyList;
        Node *prevVertex;

        Node(const std::string &id): id{id}, pathLength{-1}, prevVertex{nullptr} {}
        void printPath(std::ofstream &out) const;
    };

    std::list<Node*> vertexList;
    hashTable vertexHash; 

public:
    Graph();
    void dijkstra();

private:
    void output();

};

#endif //GRAPH_H