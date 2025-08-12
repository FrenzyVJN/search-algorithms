#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include "graph.h"

using namespace std;

void BeamSearchWeighted(Graph &g, string start, string goal, int beamWidth) {
    vector<pair<vector<string>, int>> frontier = {{{start}, 0}};
    set<string> visited;
    visited.insert(start);

    while (!frontier.empty()) {
        for (auto &p : frontier) {
            if (p.first.back() == goal) {
                cout << "Beam Search (Weighted) Path: ";
                for (auto &node : p.first) cout << node << " ";
                cout << "\nTotal Cost: " << p.second << "\n";
                return;
            }
        }

        vector<pair<vector<string>, int>> newFrontier;
        for (auto &p : frontier) {
            string node = p.first.back();
            for (auto &neighborPair : g.weightedAdj[node]) {
                string neighbor = neighborPair.first;
                int weight = neighborPair.second;

                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    auto newPath = p.first;
                    newPath.push_back(neighbor);
                    int newCost = p.second + weight;
                    newFrontier.push_back({newPath, newCost});
                }
            }
        }


        sort(newFrontier.begin(), newFrontier.end(),
             [&](auto &a, auto &b) {
                 int f_a = a.second + g.heuristic[a.first.back()];
                 int f_b = b.second + g.heuristic[b.first.back()];
                 return f_a < f_b;
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
    BeamSearchWeighted(g, "S", "G", 2);
    return 0;
}
