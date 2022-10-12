#ifndef BFS_H_
#define BFS_H_

#include<iostream>
#include<list>
using namespace std;
class Graph {
private:
	int V;                                      // No. of vertices
	list<int>* adjList;
	void DFS_visit(int v, bool visited[]);

public:
	Graph(int V);                               // Constructor
	void addEdge(int, int);                     // function to add an edge to graph
	void BFS(int);                              // prints BFS traversal from a given source s
	void DFS(int);
};
Graph::Graph(int V) {
	this->V = V;
	adjList = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adjList[v].push_back(w);
}
void Graph::BFS(int s) {
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	list<int> queue;
	queue.push_back(s);
	visited[s] = true;
	list<int>::iterator it;
	while (!queue.empty()) {
		s = queue.front();                      // Dequeue a vertex from queue and print it
		cout << s << " ";
		queue.pop_front();
		for (it = adjList[s].begin(); it != adjList[s].end(); it++) {  // Get all adjacent vertices of the dequeued vertex s.If a adjacent has not been visited, then mark it visitedand enqueue it
			if (!visited[*it]) {
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}
}
#endif // !BFS_H_