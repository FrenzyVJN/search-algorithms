#include<iostream>
#include "graph.h"
#include <algorithm>

bool DLS(Graph &g, string current, string goal, int depth, vector<string> &path) {
    if (depth == 0 && current == goal) {
        path.push_back(current);
        return true;
    }
    if (depth > 0) {
        path.push_back(current);
        for (auto &neighbor : g.adj[current]) {
            if (find(path.begin(), path.end(), neighbor) == path.end()) {
                if (DLS(g, neighbor, goal, depth - 1, path)) return true;
            }
        }
        path.pop_back();
    }
    return false;
}

void IDDFS(Graph &g, string start, string goal, int maxDepth) {
    for (int depth = 0; depth <= maxDepth; depth++) {
        vector<string> path;
        if (DLS(g, start, goal, depth, path)) {
            cout << "IDDFS Path found at depth " << depth << ": ";
            for (size_t i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "No path found within depth " << maxDepth << ".\n";
}

int main() {
    Graph g = createGraph();
    IDDFS(g, "S", "G", 5);
    return 0;
}
