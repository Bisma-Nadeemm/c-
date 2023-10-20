#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Graph class using adjacency list
class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void DFS(int startVertex);

private:
    int vertices;
    vector<vector<int>> adjList;
};

Graph::Graph(int v) {
    vertices = v;
    adjList.resize(v);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
}

void Graph::DFS(int startVertex) {
    vector<bool> visited(vertices, false);
    stack<int> stack;

    visited[startVertex] = true;
    stack.push(startVertex);

    while (!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();
        cout << currentVertex << " ";

        for (int adjacentVertex : adjList[currentVertex]) {
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                stack.push(adjacentVertex);
            }
        }
    }
}

int main() {
    Graph g(7); // Create a graph with 7 vertices

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "Depth-First Traversal starting from vertex 0: ";
    g.DFS(0);

    return 0;
}
