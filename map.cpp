// 8-Puzzle hashTable
// Collin Trehar and Levi Franklin
// Speed and Power Studios

#include <iostream>
#include <list>
#include <puzzleBoard.h>
#include <vector>

using namespace std;

 //check a node to see if it has been visited
 // if it has already been visited move on
 // else put its adjacent nodes in the queue 
 // move current node to the visited queue 
 // move on to one of the adjacent nodes 

class Graph {
  int numberOfNodes;
  list<int>* adjacentList;
  bool* visited;

   public:
  Graph(int vertices);
  void addEdge(int sourceNode, int destinationNode);
  void BFS(int startNode);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
  numberOfNodes = vertices;
  adjacentList = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int sourceNode, int destinationNode) {
  adjacentList[sourceNode].push_back(destinationNode);
  adjacentList[destinationNode].push_back(sourceNode);
}

// BFS algorithm
void Graph::BFS(int startVertex) {
  visited = new bool[numberOfNodes];
  for (int i = 0; i < numberOfNodes; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "Visited " << currVertex << " ";
    queue.pop_front();

    for (i = adjacentList[currVertex].begin(); i != adjacentList[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}