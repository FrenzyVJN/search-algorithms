#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include "graph.h"

void BFS_History(Graph &g, string start, string goal) {
    queue<vector<string>> q;
    set<string> visited;
    vector<string> history;

    q.push({start});
    visited.insert(start);
    history.push_back(start);

    while (!q.empty()) {
        vector<string> path = q.front();
        q.pop();

        string node = path.back();

        if (node == goal) {
            cout << "BFS History Path found: ";
            for (size_t i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << "\nVisited order: ";
            for (auto &h : history) cout << h << " ";
            cout << "\n";
            return;
        }

        for (auto &neighbor : g.adj[node]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                history.push_back(neighbor);
                vector<string> newPath = path;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }
    }
}

int main() {
    Graph g = createGraph();
    BFS_History(g, "S", "G");
    return 0;
}
