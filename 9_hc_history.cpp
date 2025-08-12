#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include "graph.h"

using namespace std;

void HillClimbingHistoryWeighted(Graph &g, string start, string goal) {
    string current = start;
    vector<string> path = {start};
    vector<string> history;
    set<string> visited;
    int totalCost = 0;

    while (current != goal) {
        visited.insert(current);
        history.push_back(current);

        string nextNode = "";
        int bestHeuristic = INT_MAX;
        int edgeCost = 0;

        for (auto &neighborPair : g.weightedAdj[current]) {
            string neighbor = neighborPair.first;
            int weight = neighborPair.second;

            if (!visited.count(neighbor) && g.heuristic[neighbor] < bestHeuristic) {
                bestHeuristic = g.heuristic[neighbor];
                nextNode = neighbor;
                edgeCost = weight;
            }
        }

        if (nextNode == "") {
            history.push_back("(stuck at " + current + ")");
            break;
        }

        totalCost += edgeCost;
        path.push_back(nextNode);
        current = nextNode;
    }

    history.push_back(current);

    cout << "Hill Climbing (Weighted, History) Path: ";
    for (auto &p : path) cout << p << " ";
    cout << "\nTotal Cost: " << totalCost;
    cout << "\nVisited order: ";
    for (auto &h : history) cout << h << " ";
    cout << "\n";
}

int main() {
    Graph g = createGraph();
    HillClimbingHistoryWeighted(g, "S", "G");
    return 0;
}
