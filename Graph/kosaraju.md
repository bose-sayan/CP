# Prerequisites
- ## SCC
        A maximal connected component where there exists a path from every vertex to every other vertex in the component.
        Two SCC never intersect.
- ## Condensation graph
        If all the SCC are considered as vertices, we get a DAG with the following property:
            If there exists an edge from C1 to C2, i.e., 
            C1 -> C2
            then outTime[C2] < outTime[C1]
        where outTime[x] is the time x gets popped off from the dfs' call stack
- ## Transpose graph
        If all the edges are reversed in a graph, we get the transpose of that graph.

# Idea
1. Find the out times of the nodes by running dfs.
2. Sort the vertices according to out times in reverse order
    - So if u is the vertex with the highest out time, we can consider it to be the root vertex with no incoming edges from other SCC.
    - Then, if we can find all the vertices in the SCC of u, we can remove them from the graph and find the next SCC.
3. Build the condensation graph
    - We can do this by running a dfs on the transpose graph from the root vertex. All the nodes which gets visited in this dfs are in the same SCC. Keep marking these vertices with the same color.
    - The next time we visit any of these vertices, we can ignore them.
    - Then repeat the same step for the next unvisited vertex in the sorted order of vertices according to out times.
    - Keep doing this until all the vertices are visited.
4. Finally we would have marked all the vertices in the same SCC with the same color.

# References
- [CP-Algorithms](https://cp-algorithms.com/graph/strongly-connected-components.html)

# Practice Problems
- [CSES - Flight Routes](https://cses.fi/problemset/task/1682)
- [CSES - Planets and Kingdoms](https://cses.fi/problemset/task/1683)