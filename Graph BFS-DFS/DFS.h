#ifndef DFS_H_
#define DFS_H_
#include "BFS.h"
void Graph::DFS_visit(int v, bool visited[]) {
	visited[v] = true;                                          // current node v is visited
	cout << v << " ";
	list<int>::iterator i;                                      // recursively process all the adjacent vertices of the node
	for (i = adjList[v].begin(); i != adjList[v].end(); i++) {
		if (!visited[*i])
			DFS_visit(*i, visited);
	}
}
// DFS traversal 
void Graph::DFS(int v) {
	bool* visited = new bool[V];                                // initially none of the vertices are visited
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	DFS_visit(v, visited);
}
#endif // !DFS_H_
