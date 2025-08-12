#include <iostream>
#include <vector>
#include <limits>
#include "graph.h"

void OracleUtil(Graph &g, string current, string goal, vector<string> &path, int currentCost, vector<string> &bestPath, int &bestCost) {
    if (current == goal) {
        if (bestPath.empty() || currentCost < bestCost) {
            bestPath = path;
            bestCost = currentCost;
        }
        return;
    }

    for (auto &edge : g.weightedAdj[current]) {
        string neighbor = edge.first;
        int weight = edge.second;

        if (find(path.begin(), path.end(), neighbor) == path.end()) {
            path.push_back(neighbor);
            OracleUtil(g, neighbor, goal, path, currentCost + weight, bestPath, bestCost);
            path.pop_back();
        }
    }
}

void OracleSearch(Graph &g, string start, string goal) {
    vector<string> path = {start};
    vector<string> bestPath;
    int bestCost = numeric_limits<int>::max();

    OracleUtil(g, start, goal, path, 0, bestPath, bestCost);

    if (!bestPath.empty()) {
        cout << "Oracle (Optimal Weighted) Path: ";
        for (auto &p : bestPath) cout << p << " ";
        cout << "\nTotal cost: " << bestCost << "\n";
    } else {
        cout << "No path found.\n";
    }
}

int main() {
    Graph g = createGraph();
    OracleSearch(g, "S", "G");
    return 0;
}
