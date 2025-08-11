#include<iostream>
#include<set>
#include<vector>
#include "graph.h"

void HillClimbingHistory(Graph &g, string start, string goal) {
    string current = start;
    vector<string> path = {start};
    vector<string> history;
    set<string> visited;

    while (current != goal) {
        visited.insert(current);
        history.push_back(current);

        string nextNode = "";
        int bestHeuristic = INT_MAX;

        for (auto &neighbor : g.adj[current]) {
            if (!visited.count(neighbor) && g.heuristic[neighbor] < bestHeuristic) {
                bestHeuristic = g.heuristic[neighbor];
                nextNode = neighbor;
            }
        }

        if (nextNode == "") {
            history.push_back("(stuck at " + current + ")");
            break;
        }

        path.push_back(nextNode);
        current = nextNode;
    }

    history.push_back(current);

    cout << "Hill Climbing (History) Path: ";
    for (auto &p : path) cout << p << " ";
    cout << "\nVisited order: ";
    for (auto &h : history) cout << h << " ";
    cout << "\n";
}

int main() {
    Graph g = createGraph();
    HillClimbingHistory(g, "S", "G");
    return 0;
}
