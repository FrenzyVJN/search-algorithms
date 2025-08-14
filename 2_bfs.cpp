#include <iostream>
#include "graph.h"
#include <queue>
#include <set>
using namespace std;

void BFS(Graph &g, string start, string goal)
{
    queue<vector<string>> q;
    set<string> visited;

    q.push({start});
    visited.insert(start);

    while (!q.empty())
    {
        vector<string> path = q.front();
        q.pop();

        string node = path.back();

        if (node == goal)
        {
            cout << "BFS Path found: ";
            for (size_t i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << "\n";
            return;
        }

        for (auto &neighbor : g.adj[node])
        {
            if (!visited.count(neighbor))
            {
                visited.insert(neighbor);
                vector<string> newPath = path;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }
    }
}

int main()
{
    Graph g = createGraph();
    BFS(g, "S", "G");
    return 0;
}
