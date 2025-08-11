#include <iostream>
#include "graph.h"
#include <algorithm> // for find

using namespace std;

void britishMuseumSearch(Graph &g, string start, string goal)
{
    vector<vector<string>> allPaths;
    vector<string> path;
    path.push_back(start);

    function<void(string)> dfs = [&](string current) {
        if (current == goal) {
            allPaths.push_back(path);
            return;
        }
        for (auto &neighbor : g.adj[current]) {
            if (find(path.begin(), path.end(), neighbor) == path.end()) {
                path.push_back(neighbor);
                dfs(neighbor);
                path.pop_back();
            }
        }
    };

    dfs(start);

    cout << "All possible paths from " << start << " to " << goal << ":\n";
    for (auto &p : allPaths) {
        for (auto &node : p) cout << node << " ";
        cout << "\n";
    }
}

int main()
{
    Graph g = createGraph();
    britishMuseumSearch(g, "S", "G");
    return 0;
}
