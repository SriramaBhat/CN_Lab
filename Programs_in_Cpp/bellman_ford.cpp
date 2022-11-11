// Program to implement Bellman Ford algorithm
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef struct Edge {
    int source;
    int destination;
    int weight;
} Edge;

class Graph {
public:
    int vertexNumber, edgeNumber;
    vector<Edge> graph;
    vector<int> distance;

    Graph(int m, int n) {
        vertexNumber = m;
        edgeNumber = n;
        distance.push_back(0);
        for (int i = 1; i < m; i++) {
            distance.push_back(INT_MAX);
        }
    }

    void printDistance() {
        cout << "Vertex\t\tDistance from source" << endl;
        for (int i = 0; i < vertexNumber; i++) {
            cout << i << "\t\t" << distance.at(i) << endl;
        }
    }

    void bellmanFord(int src) {
        for (int i = 1; i <= vertexNumber - 1; i++) {
            for (int j = 0; j < edgeNumber; j++) {
                int u = graph.at(j).source;
                int v = graph.at(j).destination;
                int w = graph.at(j).weight;
                if (distance.at(u) != INT_MAX && distance.at(u) + w < distance.at(v)) {
                    distance.at(v) = distance.at(u) + w;
                }
            }
        }

        for (int i = 0; i < edgeNumber; i++) {
            int u = graph.at(i).source;
            int v = graph.at(i).destination;
            int w = graph.at(i).weight;
            if (distance.at(u) != INT_MAX && distance.at(u) + w < distance.at(v)) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }

        printDistance();
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: " << endl;
    cin >> V >> E;
    Edge edg;
    Graph g = Graph(V, E);
    cout << "Enter the source, destination and weight of the edge in a single line: " << endl;
    for(int i=0; i<E; i++) {
        cin >> edg.source >> edg.destination >> edg.weight;
        g.graph.push_back(edg);
    }
    int src;
    cout << "Enter the source vertex:" << endl;
    cin >> src;
    g.bellmanFord(src);
    return 0;
}
