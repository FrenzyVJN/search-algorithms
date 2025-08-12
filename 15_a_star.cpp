#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include "graph.h"

struct AStarNode {
    std::vector<std::string> path;
    int cost;
    int heuristic;
    bool operator>(const AStarNode &other) const {
        return (cost + heuristic) > (other.cost + other.heuristic);
    }
};

void AStar(Graph &g, std::string start, std::string goal) {
    std::priority_queue<AStarNode, std::vector<AStarNode>, std::greater<AStarNode>> pq;
    pq.push({{start}, 0, g.heuristic[start]});
    std::set<std::string> visited;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        std::string node = current.path.back();

        if (node == goal) {
            std::cout << "A* Path: ";
            for (auto &p : current.path) std::cout << p << " ";
            std::cout << "\nCost: " << current.cost
                      << " | Heuristic: " << current.heuristic
                      << " | Total: " << current.cost + current.heuristic << "\n";
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
}

int main() {
    Graph g = createGraph();
    AStar(g, "S", "G");
    return 0;
}
