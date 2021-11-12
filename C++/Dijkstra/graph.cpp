#include "graph.h"
#include <iostream> 
#include <fstream> 

Graph::Graph(): vertexHash{40000} //constructor to build the graph 
{
    std::string infile;
    std::cout << "Enter input file: ";
    std::cin >> infile;
    std::ifstream(input);
    input.open(infile); 

    std::string v1;
    std::string v2;
    std::string weightstr;
    int weight;

    while(input >> v1) //while there is input 
    {
        input >> v2;
        input >> weightstr;
        weight = std::stoi(weightstr);

        Node *p_v1{nullptr};
        if(!(p_v1 = static_cast<Node*>(vertexHash.getPointer(v1)))) //if it doesn't exist 
        {
            p_v1 = new Node{v1};
            vertexList.push_back(p_v1);
            vertexHash.insert(v1, p_v1);
        }

        Node *p_v2{nullptr};
        if(!(p_v2 = static_cast<Node*>(vertexHash.getPointer(v2)))) //if it doesn't exist 
        {
            p_v2 = new Node{v2};
            vertexList.push_back(p_v2);
            vertexHash.insert(v2, p_v2);
        }
        p_v1->adjacencyList.push_back(Node::Edge{weight, p_v2}); //add v2 to the adjacency list of v1 
    }
}

void Graph::dijkstra() //actual dijkstra's algo 
{
    std::string startV; 
    do //make sure they enter a valid vertex
    {
        std::cout << "Enter name of starting vertex: ";
        std::cin >> startV;
    }
    while(!vertexHash.contains(startV));
    heap vertexQueue(vertexList.size()); 
    clock_t t1 = clock();

    Node *startVP = static_cast<Node *>(vertexHash.getPointer(startV));  //initialize initial vertex 
    startVP->pathLength = 0;
    vertexQueue.insert(startV, 0, startVP); 

    while(1)
    {
        std::string vID{""}; 
        int length{0};
        void* vptr{nullptr};
        if(vertexQueue.deleteMin(&vID, &length, &vptr) != 1) //while items in queue 
        {
            Node &vertex = *static_cast<Node *>(vptr);
            for(const Node::Edge &edge : vertex.adjacencyList) //for each edge 
            {
                Node &d_Vertex = *(edge.destVertex);

                if(d_Vertex.pathLength == -1) // if this is the first time 
                {
                    d_Vertex.pathLength = length + edge.weight;
                    d_Vertex.prevVertex = static_cast<Node *>(vptr);
                    vertexQueue.insert(d_Vertex.id, d_Vertex.pathLength, &d_Vertex);
                }

                else  
                {
                    if(length + edge.weight < d_Vertex.pathLength) //if the new path is better 
                    {
                        d_Vertex.pathLength = length + edge.weight;
                        d_Vertex.prevVertex = static_cast<Node *>(vptr);
                    }
                    vertexQueue.setKey(d_Vertex.id, d_Vertex.pathLength); //set the key to the new dmin 
                }
            }
        }
        else
            break; 
    }

    clock_t t2 = clock();
    double time = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
    std::cout << "Total time (in seconds) to apply Dijkstra's algorithm: " << time << '\n';

    output(); 
}

void Graph::output() //output the paths
{
    std::string outfile;
    std::cout << "Enter name of output file: ";
    std::cin >> outfile;
    std::ofstream(output);
    output.open(outfile);

    for( const Node *vertex : vertexList )
    {
        output << vertex->id << ": ";
        if(vertex->pathLength == -1) //means we didn't reach in dikstra's 
            output << "NO PATH\n";
        else
        {
            output << vertex->pathLength << " [";
            vertex->printPath(output); //recurse on the vertex
            output << "]\n";
        }
    }
}

void Graph::Node::printPath(std::ofstream &output) const
{
    if(prevVertex) //if it has a pervious vertex
    {
        prevVertex->printPath(output); //recurse to get all vertices 
        output << ", ";
    }
    output << id; //once we reach the end, output current ID 
}