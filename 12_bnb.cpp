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
            cout << "Branch & Bound (Weighted) Path: ";
            for (size_t i = 0; i < current.path.size(); ++i) {
                cout << current.path[i];
                if (i != current.path.size() - 1) cout << " -> ";
            }
            cout << "\nTotal cost: " << current.cost << "\n";
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

    cout << "No path found.\n";
}

int main() {
    Graph g = createGraph();
    BranchAndBound(g, "S", "G");
    return 0;
}
