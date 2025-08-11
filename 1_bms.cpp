#include <iostream>
#include "graph.h"
#include <algorithm> // for find
#include <vector>
#include <string>

using namespace std;

void britishMuseumSearch(Graph &g, string start, string goal)
{
    vector<vector<string>> allPaths;
    vector<string> path;

    path.push_back(start);

    {
        struct Recursion
        {
            static void run(Graph &g, string current, string goal, vector<string> &path, vector<vector<string>> &allPaths)
            {
                if (current == goal)
                {
                    allPaths.push_back(path);
                    return;
                }
                for (auto &neighbor : g.adj[current])
                {
                    if (find(path.begin(), path.end(), neighbor) == path.end())
                    {
                        path.push_back(neighbor);
                        run(g, neighbor, goal, path, allPaths);
                        path.pop_back();
                    }
                }
            }
        };
        Recursion::run(g, start, goal, path, allPaths);
    }

    cout << "All possible paths from " << start << " to " << goal << ":\n";
    for (auto &p : allPaths)
    {
        for (auto &node : p)
            cout << node << " ";
        cout << "\n";
    }
}

int main()
{
    Graph g = createGraph();
    britishMuseumSearch(g, "S", "G");
    return 0;
}
