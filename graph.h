#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Graph {
public:
    unordered_map<string, vector<string>> adj;

    unordered_map<string, vector<pair<string, int>>> weightedAdj;

    unordered_map<string, int> heuristic;

    void addEdge(const string &u, const string &v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void addWeightedEdge(const string &u, const string &v, int w) {
        weightedAdj[u].push_back({v, w});
        weightedAdj[v].push_back({u, w});
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

    g.addWeightedEdge("S", "A", 3);
    g.addWeightedEdge("S", "B", 5);
    g.addWeightedEdge("A", "D", 3);
    g.addWeightedEdge("A", "B", 4);
    g.addWeightedEdge("B", "C", 4);
    g.addWeightedEdge("C", "E", 6);
    g.addWeightedEdge("D", "G", 5);

    g.heuristic["S"] = 10;
    g.heuristic["A"] = 7;
    g.heuristic["B"] = 6;
    g.heuristic["C"] = 7;
    g.heuristic["E"] = 6;
    g.heuristic["D"] = 5;
    g.heuristic["G"] = 0;

    return g;
}

#endif
