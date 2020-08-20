/*
    Student Name:   Maria Azam
    Student ID:     200402217
    Date:           Wednesday, August 19, 2020

    Purpose:        Implement Dijkstra's Algorithm to find the least cost path from one node to all other vertices in a graph.
    Assumptions:    All nodes/vertices are referred to by consectuive positive integers, beginning with 0.
                    All weights are positive integers.
                    The graph is directed.
                    There may be no more than 100 nodes/vertices in the graph.
*/

#include <iostream>
#include <limits>
using namespace std;

const int MAX_VERTEX = 20;
void addEdge(int matrix[][MAX_VERTEX], int s, int d, int w);
void printSoulution(int cost[], int v, int node);
int getMinDistance(int cost, bool visited[], int v);
void dijkstra(int matrix[][MAX_VERTEX], int node, int v);

int main()
{
    int matrix[MAX_VERTEX][MAX_VERTEX];

    //Prompt user to enter number of vertices & edges in graph
    int vertices;
    cout << "Enter the number of vertices, to a maximum of 100: ";
    cin >> vertices;

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;
    int s, d;
    int w;

    //Prompt user to enter edges & add them to the matrix
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the source node, destination node, and weight as positive integers: ";
        cin >> s >> d >> w;
        addEdge(matrix, s, d, w);
    }

    //Prompt user to enter starting node & call Dijkstra's Algorithm starting from this node
    int node;
    cout << "Enter the node to find the shortest path from: ";
    cin >> node;
    dijkstra(matrix, node, vertices);

    return 0;
}

//Add a user-input edge to the matrix
void addEdge(int matrix[][MAX_VERTEX], int s, int d, int w)
{
    matrix[s][d] = w;
}

//Find the unvisited node with the least cost to it
int getMinDistance(int cost[], bool visited[], int v)
{
    //Initialize the minimum cost value to the upper bound of C++ integers
    int minimum = INT_MAX;
    int minIndex;

    //Traverse through the set of unvisited nodes, finding the one with the least cost & its index
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false && cost[i] < minimum)
        {
            minimum = cost[i];
            minIndex = i;
        }
    }

    //Return index
    return minIndex;
}

//Print the least cost from the source node to each node in the graph
void printSolution(int cost[], int v, int node)
{

    cout << "The least cost path from " << node << " to all other nodes is as follows:" << endl;;
    cout << "Node   Cost" << endl;
    for (int i = 0; i < v; i++)
        cout << i << "      " << cost[i] << endl;

}

//Implementation of Dijkstra's Algorithm
void dijkstra(int matrix[][MAX_VERTEX], int node, int v)
{
    bool visited[v];    //Indicates whether or not each node has been visited
    int cost[v];        //Indicates least cost path to given node

    //Initialize all nodes to unvisited and infinite cost, unless source node
    for (int i = 0; i < v; i++)
    {
        if (i == node)
        {
            cost[i] = 0;
        }
        else
        {
            cost[i] = INT_MAX; //INT_MAX treated as infinity
            visited[i] = false;
        }
    }

    for (int i = 0; i < v - 1; i++)
    {
        //Locate the next unvisited node with the least cost to it & set it as visited
        int minUnvisited = getMinDistance(cost, visited, v);
        visited[minUnvisited] = true;

        //Consider every adjacent vertex that is unvisited
        for (int j = 0; j < v; j++)
        {
            //Is the distance to this node plus the weight of the edge less than our currently known least cost to this node?
            if (!visited[j] && matrix[minUnvisited][j] && cost[minUnvisited] != INT_MAX && cost[minUnvisited] + matrix[minUnvisited][j] < cost[j])
            {
                //If so, update the least cost to this node
                cost[j] = cost[minUnvisited] + matrix[minUnvisited][j];
            }
        }
    }

    printSolution(cost, v, node);
}