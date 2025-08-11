#include<iostream>
#include<vector>
#include "graph.h"

void OracleUtil(Graph &g, string current, string goal,
                vector<string> &path, vector<string> &bestPath) {
    if (current == goal) {
        if (bestPath.empty() || path.size() < bestPath.size()) {
            bestPath = path;
        }
        return;
    }

    for (auto &neighbor : g.adj[current]) {
        if (find(path.begin(), path.end(), neighbor) == path.end()) {
            path.push_back(neighbor);
            OracleUtil(g, neighbor, goal, path, bestPath);
            path.pop_back();
        }
    }
}

void OracleSearch(Graph &g, string start, string goal) {
    vector<string> path = {start};
    vector<string> bestPath;
    OracleUtil(g, start, goal, path, bestPath);

    cout << "Oracle (Optimal) Path: ";
    for (auto &p : bestPath) cout << p << " ";
    cout << "\nPath length: " << bestPath.size() - 1 << "\n";
}

int main() {
    Graph g = createGraph();
    OracleSearch(g, "S", "G");
    return 0;
}
