#include<iostream>
#include<set>
#include<vector>
#include "graph.h"

bool DFS_HistoryUtil(Graph &g, string current, string goal, 
                     set<string> &visited, vector<string> &path, vector<string> &history) {
    visited.insert(current);
    history.push_back(current);
    path.push_back(current);

    if (current == goal) return true;

    bool deadEnd = true;
    for (auto &neighbor : g.adj[current]) {
        if (!visited.count(neighbor)) {
            deadEnd = false;
            if (DFS_HistoryUtil(g, neighbor, goal, visited, path, history)) return true;
        }
    }

    if (deadEnd) {
        history.push_back("(dead-end:" + current + ")");
    }

    path.pop_back();
    return false;
}

void DFS_History(Graph &g, string start, string goal) {
    set<string> visited;
    vector<string> path, history;

    if (DFS_HistoryUtil(g, start, goal, visited, path, history)) {
        cout << "DFS History Path found: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << "\nVisited order/history: ";
        for (auto &h : history) cout << h << " ";
        cout << "\n";
    } else {
        cout << "No path found.\n";
    }
}

int main() {
    Graph g = createGraph();
    DFS_History(g, "S", "G");
    return 0;
}
