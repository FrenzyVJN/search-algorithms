#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include "graph.h"

struct PathCostH {
    vector<string> path;
    int cost;
    int heuristic;
    bool operator>(const PathCostH &other) const {
        return (cost + heuristic) > (other.cost + other.heuristic);
    }
};

void BranchAndBoundEH(Graph &g, string start, string goal) {
    priority_queue<PathCostH, vector<PathCostH>, greater<PathCostH>> pq;
    pq.push({{start}, 0, g.heuristic[start]});
    set<string> visited;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        string node = current.path.back();

        if (node == goal) {
            cout << "Branch & Bound with Estimated Heuristic (Weighted) Path: ";
            for (auto &p : current.path) cout << p << " ";
            cout << "\nTotal cost: " << current.cost
                 << "\nCost + Heuristic: " << current.cost + current.heuristic << "\n";
            return;
        }

        if (visited.count(node)) continue;
        visited.insert(node);

        for (auto &[neighbor, weight] : g.weightedAdj[node]) {
            auto newPath = current.path;
            newPath.push_back(neighbor);
            pq.push({newPath, current.cost + weight, g.heuristic[neighbor]});
        }
    }

    cout << "No path found.\n";
}

int main() {
    Graph g = createGraph();
    BranchAndBoundEH(g, "S", "G");
    return 0;
}
