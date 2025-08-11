#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include "graph.h"

struct PathCost {
    vector<string> path;
    int cost;
    bool operator>(const PathCost &other) const {
        return cost > other.cost;
    }
};

void BranchAndBound(Graph &g, string start, string goal) {
    priority_queue<PathCost, vector<PathCost>, greater<PathCost>> pq;
    pq.push({{start}, 0});
    set<string> visited;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        string node = current.path.back();

        if (node == goal) {
            cout << "Branch & Bound Path: ";
            for (auto &p : current.path) cout << p << " ";
            cout << "\nCost: " << current.cost << "\n";
            return;
        }

        if (visited.count(node)) continue;
        visited.insert(node);

        for (auto &neighbor : g.adj[node]) {
            auto newPath = current.path;
            newPath.push_back(neighbor);
            pq.push({newPath, current.cost + 1});
        }
    }
}

int main() {
    Graph g = createGraph();
    BranchAndBound(g, "S", "G");
    return 0;
}
