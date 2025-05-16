#ifndef HEAP_H
#define HEAP_H

#include "graph.h"

class Graph;
using namespace std;

class MinHeap {
public:
    //infinite int variable
    int inf = INT_MAX;

    MinHeap(int capacity) {

        this->size = capacity;
        this->capacity = capacity;

        //Initializing the keyArray
        keyArray = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            if (i == 0) {
                keyArray[i] = 0;
            }
            else {
                keyArray[i] = inf;
            }
        }

        //Initializing the heapArray
        heapArray = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            heapArray[i] = i;
        }

        //Initializing the position
        position = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            position[i] = i;
        }
    }

    ~MinHeap() {
        //deleting memory space created by the arrays
        delete[] keyArray;
        delete[] heapArray;
        delete[] position;
    };
    //a vertix
    void insert(int vertex, int key) {

    }

    int** setAdjMatrix(int** matrix) {
        adjMatrix = matrix;
        return adjMatrix;
    }

    int extractMin() {
        int min = heapArray[0];
        int lastNode = heapArray[size - 1];

        heapArray[0] = lastNode;
        position[lastNode] = 0;
        size--;

        //update heap
        //since the first value in the heapArray is extracted
        //the heaparray needs to be updated
        minHeapify(0);

        //smallest value index is returned
        return min;

    }
    void decreaseKey(int vertex, int newKey) {
        int i = position[vertex];
        keyArray[vertex] = newKey;

        while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
            // Swap current node with its parent
            int parentIdx = (i - 1) / 2;

            //switch positions
            int temp = heapArray[i];
            heapArray[i] = heapArray[parentIdx];
            heapArray[parentIdx] = temp;

            // Update positions
            position[heapArray[i]] = i;
            position[heapArray[parentIdx]] = parentIdx;

            i = parentIdx;
        }
    }

    bool isInMinHeap(int vertex) {
        for (int i = 0; i < size; i++) {
            if (heapArray[i] == vertex) {
                return true;
            }
        }
        return false;
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    int* heapArray;        //// Heap of vertex indices
    int* keyArray;         //// Corresponding key values
    int* position;         //// Maps vertex to its position in heap
    int capacity;
    int size;

    int** adjMatrix;

    //this updates the heap and makes sure it is updated
    void minHeapify(int idx) {
        int minimum = idx;
        int left = 2 * idx;
        int right = 2 * idx + 1;

        //locating the minimum
        //checking left side
        if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[minimum]])
            minimum = left;
        //checking right side
        if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[minimum]])
            minimum = right;

        if (minimum != idx) {
            // switching the heap array index with the minimum value index
            int minimumVertex = heapArray[minimum];
            int indexVertex = heapArray[idx];
            int minTemp;

            //switching the minimum value in the heapArray
            minTemp = heapArray[minimum];
            heapArray[minimum] = heapArray[idx];
            heapArray[idx] = minTemp;

            //updating the minimum in the position array
            position[minimumVertex] = idx;
            position[indexVertex] = minimum;

            minHeapify(minimum);
        }

    }
};

#endif
