#include<iostream>
#include<set>
#include<vector>
#include "graph.h"

void BeamSearch(Graph &g, string start, string goal, int beamWidth) {
    vector<vector<string>> frontier = {{start}};
    set<string> visited;
    visited.insert(start);

    while (!frontier.empty()) {
        for (auto &path : frontier) {
            if (path.back() == goal) {
                cout << "Beam Search Path: ";
                for (auto &p : path) cout << p << " ";
                cout << "\n";
                return;
            }
        }

        vector<vector<string>> newFrontier;
        for (auto &path : frontier) {
            string node = path.back();
            for (auto &neighbor : g.adj[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
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
    BeamSearch(g, "S", "G", 2);
    return 0;
}
