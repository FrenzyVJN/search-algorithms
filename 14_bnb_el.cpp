#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include "graph.h"

struct PathCost_EL {
    vector<string> path;
    int cost;
    bool operator>(const PathCost_EL &other) const {
        return cost > other.cost;
    }
};

void BranchAndBoundEL(Graph &g, string start, string goal) {
    priority_queue<PathCost_EL, vector<PathCost_EL>, greater<PathCost_EL>> pq;
    pq.push({{start}, 0});
    set<string> visited;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        string node = current.path.back();

        if (node == goal) {
            cout << "Branch & Bound (Early Exit) Path: ";
            for (auto &p : current.path) cout << p << " ";
            cout << "\nCost: " << current.cost << "\n";
            return;
        }

        if (visited.count(node)) continue;
        visited.insert(node);

        for (auto &[neighbor, weight] : g.weightedAdj[node]) {
            auto newPath = current.path;
            newPath.push_back(neighbor);
            pq.push({newPath, current.cost + weight});
        }
    }
}

int main() {
    Graph g = createGraph();
    BranchAndBoundEL(g, "S", "G");
    return 0;
}
