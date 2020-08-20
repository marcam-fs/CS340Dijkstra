/*
    Student Name:   Maria Azam
    Student ID:     200402217
    Date:           Wednesday, August 19, 2020

    Purpose:        Implement Dijkstra's Algorithm to find the least cost path from one node to all other vertices in a graph.
    References:     
*/

#include <iostream>
using namespace std;

const int MAX_VERTEX = 100;
void addEdge(int matrix[][MAX_VERTEX], int s, int d, int w);
void printGraph(int matrix[][MAX_VERTEX], int n);

int main()
{

    int matrix[MAX_VERTEX][MAX_VERTEX];

    //Prompt user to enter number of vertices in graph
    int vertices;
    cout << "Enter the number of vertices, to a maximum of 100: ";
    cin >> vertices;

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;
    int s, d, w;
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the source node, destination node, and weight: ";
        cin >> s >> d >> w;
        addEdge(matrix, s, d, w);
    }

    printGraph(matrix, vertices);

    return 0;
}


void addEdge(int matrix[][MAX_VERTEX], int s, int d, int w)
{
    matrix[s][d] = w;
}

void printGraph(int matrix[][MAX_VERTEX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}