[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Omar Vizarraga

## Description
Briefly describe what your program does and how the code is structured.

The program creates a graph and inserts edges that are all connected
through some vertex and path. When a graph object is created a adjMatrix
is created for the vertexes. You then add edges to the vertexes using a addEdge 
method found in the graph class. Then once the primMST() function is called onto
that graph object that was created, it will then create a heap object. When
the heap object is created, a keyArray, heapArray,
and a position array are created. Which will all be used in order to keep track of
values that will help find the MST of the graph. A heap class is used
in order to keep track of the edges with the least weight. The heap
is updated once a value is taken out and used for the MST path. Once
there is no more vertexes in the heap it means all vertexes have been visited.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logn)         |
| Extract Min          | O(logn)         |
| Decrease Key         | O(logn)         |
| Prim’s MST Overall   | O(n^2)          |

_Explain why your MST implementation has the above runtime._

Insert in MinHeap:
When inserting into the heap, it will go through logn elements
because it will either be smaller or larger than the root. Then
when adjusting the heap it will only need to just one side which
has height logn.

Extract Min:
Since the method just get the minimum value the uses minHeapify,
it adds logn to the time complexity of the method which otherwise
would just be O(1).

Decrease Key:
The time complexity is O(logn) because when the heap is updated
it will either upheap on the left or right, as a binary tree, and
to go through the height of the tree would take logn. Accesing
the pos

Prim’s MST Overall:
The primMST() has a time complexity of O(n^2) because there is a nested for loop that traverses
from i=o to the amount of vertices there is. Since they are ensted it is n * n making it n^2.
Where n is the number of vertices.

## Test Case Description

Input:  
Graph g(6);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 8);
g.addEdge(1, 2, 10);
g.addEdge(1, 3, 7);
g.addEdge(2, 4, 5);
g.addEdge(2, 5, 6);
g.addEdge(3, 4, 6);
g.addEdge(4, 5, 4);

g.primMST();

I drew out this example and followed the prims algorithm rules
in order to find the mst edges and the total cost. I ended up finding that
the total cost was 24. When I checked to see if the edges matched
the output they did.

## Challenges Faced
The main thing I struggled with was trying to get the program
to search through the adjacency Matrix a row at a time and 
updating the keyArray correctly using a for loop and then searching the 
next row index with the minimum to update the keyArray. After trying for a 
while I was able to get it to work but the output was only correct for the specific
example problem given. I used my own custom graph with input edges
to see if my program would work but it didn't. It would only work
if the keyArray values that needed to be updated were the next values
in the keyArray and didn't need to go back to previous indexes in the
adjMatrix for that row.

After failing to figure out how to use the position matrix in order 
to get the correct output for any , I did some research to see how it 
is used. I figured out that the position matrix keeps track of where the
vertex is in the heapArray.