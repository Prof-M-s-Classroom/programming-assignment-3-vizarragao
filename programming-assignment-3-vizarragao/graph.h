#ifndef GRAPH_H
#define GRAPH_H
#include <cmath>

#include "heap.h"

using namespace std;

class Graph {

//first need to create a constructor
public:
    Graph(int vertices) {

        this->numVertices = vertices;

        //Creating infinite int
        int inf = INT_MAX;

        //Creating adjacency Matrix
        adjMatrix = new int*[numVertices];

        //Setting Values to matrix when Graph is called
        for (int i = 0; i < numVertices; i++){
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                if (i == j) {
                    adjMatrix[i][j] = 0;
                }
                else {
                    adjMatrix[i][j] = inf;
                }
            }
            cout<< "\n";
        }
    }

    ~Graph() {
        //deleting the memory space for the adjMatrix
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void printAdjMatrix() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] == INT_MAX) {
                    cout<<"INF"<< " ";
                }

                else {
                    cout << adjMatrix[i][j] << " ";
                }
            }
            cout << "\n";
        }

    }

    int** getAdjMatrix() {
        return adjMatrix;
    }

    void primMST() {
        // Must print MST edges and total weight
        MinHeap m(numVertices);
        m.setAdjMatrix(adjMatrix);

        //The mst will be stored in this array
        int* parent = new int[numVertices];

        //Setting initial values of 0 to the parent array
        for (int i = 0; i < numVertices; i++) {
            parent[i] = 0;
        }

        for (int i = 0; i < numVertices; i++) {
            if (m.isEmpty() != true) {
                int min = m.extractMin();

                for (int i = 0; i < numVertices; i++) {
                    int weight = m.adjMatrix[min][i];
                    if (weight && weight != m.inf && m.isInMinHeap(i) && weight < m.keyArray[i]) {
                        parent[i] = min;
                        m.decreaseKey(i, weight);
                    }
                }
            }
        }

        // Output MST edges and weights
        int mstCost = 0;
        // Output MST
        for (int i = 1; i < numVertices; i++) {
            mstCost += m.adjMatrix[i][parent[i]];
            cout << parent[i] << " -- " << i << "  " << "(" << m.adjMatrix[i][parent[i]]<< ")" << endl;
        }
        cout << "Total Cost: " <<mstCost;
        //freeing memory space from the parent array
        delete[] parent;
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif