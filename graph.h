#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using namespace std;

class Graph {
public:
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> heuristic;

    void addEdge(const string &u, const string &v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

Graph createGraph() {
    Graph g;
    g.addEdge("S", "A");
    g.addEdge("S", "B");
    g.addEdge("B", "A");
    g.addEdge("B", "C");
    g.addEdge("C", "E");
    g.addEdge("A", "D");
    g.addEdge("D", "G");

    g.heuristic["S"] = 10;
    g.heuristic["A"] = 7;
    g.heuristic["B"] = 6;
    g.heuristic["C"] = 7;
    g.heuristic["E"] = 5;
    g.heuristic["D"] = 6;
    g.heuristic["G"] = 0;

    return g;
}

#endif
