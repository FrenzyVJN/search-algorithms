#include<iostream>
#include<set>
#include<vector>
#include "graph.h"

void HillClimbing(Graph &g, string start, string goal) {
    string current = start;
    vector<string> path = {start};
    set<string> visited;

    while (current != goal) {
        visited.insert(current);

        string nextNode = "";
        int bestHeuristic = INT_MAX;

        for (auto &neighbor : g.adj[current]) {
            if (!visited.count(neighbor) && g.heuristic[neighbor] < bestHeuristic) {
                bestHeuristic = g.heuristic[neighbor];
                nextNode = neighbor;
            }
        }

        if (nextNode == "") {
            cout << "Stuck at: " << current << " (local maxima)\n";
            break;
        }

        path.push_back(nextNode);
        current = nextNode;
    }

    cout << "Hill Climbing Path: ";
    for (auto &p : path) cout << p << " ";
    cout << "\n";
}

int main() {
    Graph g = createGraph();
    HillClimbing(g, "S", "G");
    return 0;
}
