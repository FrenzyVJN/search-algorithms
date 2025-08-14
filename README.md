## Search Algorithms (AI Assignment)

This repository contains minimal C++ implementations of classic informed and uninformed search algorithms

### Graph Model
`graph.h` defines:
- `adj`: unweighted undirected adjacency list (for BFS / DFS / IDDFS / history variants / British Museum)
- `weightedAdj`: weighted undirected adjacency list (for cost-based & heuristic searches)
- `heuristic`: admissible-ish heuristic estimates to goal (used by Hill Climbing, Beam, Branch & Bound + heuristic, and A*)

Nodes: S (start), A, B, C, D, E, G (goal)

### Implemented Algorithms
| File | Algorithm | Description |
|------|-----------|-------------|
| `1_bms.cpp` | British Museum (Brute Force enumeration) | Exhaustively lists every simple path S->G |
| `2_bfs.cpp` | Breadth-First Search | Finds shortest path in edge count |
| `3_dfs.cpp` | Depth-First Search (first solution) | May not be shortest |
| `4_bfs_dfs.cpp` | Iterative Deepening Depth-First (IDDFS) | Combines DFS space efficiency with BFS optimal depth |
| `5_bfs_history.cpp` | BFS + visitation order | Prints discovered order |
| `6_dfs_history.cpp` | DFS + history & dead-end annotations | Marks dead-ends as `(dead-end:X)` |
| `7_hc.cpp` | Greedy Hill Climbing | Susceptible to local optima |
| `8_beam_search.cpp` | Weighted Beam Search | Narrows frontier to beam width by f = g + h |
| `9_hc_history.cpp` | Hill Climbing + history | Shows path, total edge cost, visited order |
| `10_beam_search_history.cpp` | Beam Search + history | Tracks visited order; heuristic ranking |
| `11_oracle.cpp` | Oracle exhaustive optimal search | Enumerates all simple weighted paths (exponential) |
| `12_bnb.cpp` | Branch & Bound (Uniform-Cost style) | Expands least-cost partial path |
| `13_bnb_eh.cpp` | Branch & Bound + heuristic (best-first) | Equivalent to A* without closed-set improvement |
| `14_bnb_el.cpp` | Branch & Bound (Early Exit) | Stops at first goal popped (like UCS) |
| `15_a_star.cpp` | A* Search | Uses f = g + h (optimal if h admissible & consistent) |

### Building & Running
Use the provided script:
```
./run_search.sh
```
Select a number (1-15) to compile & execute that algorithm. The script:
1. Compiles with `g++  <file>.cpp -o <file>.out`
2. Runs the produced executable
3. Cleans all `*.out` on exit

Manual example:
```
g++ -std=c++17 2_bfs.cpp -o bfs && ./bfs
```
