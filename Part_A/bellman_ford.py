# Program to implement Bellman Ford algorithm
from sys import maxsize


# Class denoting the graph for the algorithm to be applied
class Graph:
    def __init__(self, vertices):
        self.V = vertices  # Initializing the number of vertices
        self.graph = []

    def add_edge(self, src, destination, wt):
        self.graph.append([src, destination, wt])  # Adding an edge to the graph list

    def print_distance(self, dist):
        print("Vertex\t\tDistance from source")
        for i in range(self.V):
            print("{}\t\t{}".format(i, dist[i]))  # Printing the result

    def bellman_ford(self, src):
        dist = [maxsize] * self.V
        dist[src] = 0

        for i in range(self.V - 1):
            for u, v, w in self.graph:
                if dist[u] != maxsize and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

        for u, v, w in self.graph:
            if dist[u] != maxsize and dist[u] + w < dist[v]:
                print("Graph contains negative weight cycle")  # Checking if negetive weighted cycle is present
                return

        self.print_distance(dist)


if __name__ == "__main__":
    vertex_no = int(input("Enter the number of vertices of the graph:"))
    edges = int(input("Enter the number of edges of the graph:"))
    input_graph = Graph(vertex_no)
    print("Enter the edge in the format SOURCE, DESTINATION and WEIGHT in a SINGLE LINE:")
    for _ in range(edges):
        source, des, weight = map(int, input().split())
        input_graph.add_edge(source, des, weight)

    source = int(input("Enter the source vertex to begin the algorithm:"))
    input_graph.bellman_ford(source)