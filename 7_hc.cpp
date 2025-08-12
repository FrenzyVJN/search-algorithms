#include <iostream>
#include <string>
#include <unordered_set>
#include "graph.h"

using namespace std;

void hillClimbing(Graph &g, const string &start, const string &goal) {
    string current = start;
    unordered_set<string> visited;

    cout << "Hill Climbing path: " << current;

    while (current != goal) {
        visited.insert(current);

        string nextNode = "";
        int bestHeuristic = INT_MAX;

        for (auto &neighbor : g.weightedAdj[current]) {
            const string &node = neighbor.first;
            if (visited.count(node) == 0) {
                int h = g.heuristic[node];
                if (h < bestHeuristic) {
                    bestHeuristic = h;
                    nextNode = node;
                }
            }
        }

        if (nextNode.empty()) {
            cout << "\nNo better neighbor found. Stuck at local optimum.\n";
            return;
        }

        current = nextNode;
        cout << " -> " << current;
    }

    cout << "\nGoal reached!\n";
}

int main() {
    Graph g = createGraph();
    hillClimbing(g, "S", "G");
    return 0;
}
