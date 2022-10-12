#include <fstream>
#include <string>
#include "BFS.h"
#include "DFS.h"

int main() {
	int totalVertex, starting, first, second;
	string fileName;
	cout << "Enter the txt file name to open: ";
	cin >> fileName;
	fstream file(fileName);
	file >> totalVertex;
	file >> starting;
	if (file.is_open()) {
		cout << "Total Vertices: " << totalVertex << endl;
		cout << "Starting Vertex: " << starting << endl;
		Graph g(totalVertex);
		for (int i = 0; i < totalVertex + 1; i++) {
			file >> first >> second;;
			cout << first << ", " << second << endl;
			g.addEdge(first, second);
		}
		cout << "Depth-First Search Traversal: ";
		g.DFS(starting);
		cout << endl;
		cout << "Breath-First Search Traversal: ";
		g.BFS(starting);
		cout << endl;
		file.close();
	}
	else {
		cout << "ERROR! File cannot be found!" << endl;
	}
	return 0;
}