#include <bits/stdc++.h>
using namespace std;

// Global
const int MXN = 1e5 + 10;
vector<int> G[MXN], GT[MXN];
int out[MXN] = {}, col[MXN] = {};
int n, m, curTime = 1;

// first dfs on original graph to find the out times
void findOutTimeDfs(int src) {
    if (out[src])
        return;
    out[src] = 1;   // mark visited
    for (auto &i : G[src]) {
        findOutTimeDfs(i);
    }
    out[src] = curTime++;
}

// second dfs on transposed graph to mark vertices with their respective
// component
void findSCCDfs(int src, int c) {
    if (col[src])
        return;
    col[src] = c;
    for (auto &i : GT[src]) {
        findSCCDfs(i, c);
    }
}

void kosaraju() {
    for (int i = 0; i < n; i++) {
        if (!out[i])
            findOutTimeDfs(i);
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int u, int v) -> bool { return out[u] > out[v]; });
    for (int i = 0, c = 1; i < n; i++) {
        if (!col[order[i]])
            findSCCDfs(order[i], c++);
    }
}