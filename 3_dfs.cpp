#include <iostream>
#include "graph.h"
#include <set>
#include <vector>
#include <string>

using namespace std;

void DFS(Graph &g, string start, string goal)
{
    set<string> visited;
    vector<string> path;
    bool found = false;

    path.push_back(start);

    {
        struct Recursion
        {
            static bool run(Graph &g, string current, string goal, set<string> &visited, vector<string> &path)
            {
                visited.insert(current);

                if (current == goal)
                    return true;

                for (auto &neighbor : g.adj[current])
                {
                    if (!visited.count(neighbor))
                    {
                        path.push_back(neighbor);
                        if (run(g, neighbor, goal, visited, path))
                            return true;
                        path.pop_back();
                    }
                }
                return false;
            }
        };

        found = Recursion::run(g, start, goal, visited, path);
    }

    if (found)
    {
        cout << "DFS Path found: ";
        for (auto &p : path)
            cout << p << " ";
        cout << "\n";
    }
    else
    {
        cout << "No path found.\n";
    }
}

int main()
{
    Graph g = createGraph();
    DFS(g, "S", "G");
    return 0;
}
