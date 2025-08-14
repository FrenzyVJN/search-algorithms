#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include "graph.h"

void BeamSearchHistory(Graph &g, string start, string goal, int beamWidth) {
    vector<vector<string>> frontier = {{start}};
    vector<string> history;
    set<string> visited;
    visited.insert(start);
    history.push_back(start);

    while (!frontier.empty()) {
        for (auto &path : frontier) {
            if (path.back() == goal) {
                cout << "Beam Search (History) Path: ";
                for (size_t i = 0; i < path.size(); ++i) {
                    cout << path[i];
                    if (i != path.size() - 1) cout << " -> ";
                }
                cout << "\nVisited order: ";
                for (auto &h : history) cout << h << " ";
                cout << "\n";
                return;
            }
        }

        vector<vector<string>> newFrontier;
        for (auto &path : frontier) {
            string node = path.back();

            for (auto &[neighbor, weight] : g.weightedAdj[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    history.push_back(neighbor);
                    auto newPath = path;
                    newPath.push_back(neighbor);
                    newFrontier.push_back(newPath);
                }
            }

            for (auto &neighbor : g.adj[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    history.push_back(neighbor);
                    auto newPath = path;
                    newPath.push_back(neighbor);
                    newFrontier.push_back(newPath);
                }
            }
        }

        sort(newFrontier.begin(), newFrontier.end(), [&](auto &a, auto &b) {
            return g.heuristic[a.back()] < g.heuristic[b.back()];
        });

        if ((int)newFrontier.size() > beamWidth) {
            newFrontier.resize(beamWidth);
        }

        frontier = newFrontier;
    }

    cout << "No path found.\n";
}

int main() {
    Graph g = createGraph();
    BeamSearchHistory(g, "S", "G", 2);
    return 0;
}
