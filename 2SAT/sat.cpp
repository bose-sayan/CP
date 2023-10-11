#include <bits/stdc++.h>
using namespace std;

// Global Variables
const int MXN = 1e5 + 10;
// For denoting the negation of some literal, we add PAD to it
// ini PAD = n
int PAD = 1e5 + 10;
vector<int> G[MXN], GT[MXN];
int out[MXN] = {}, col[MXN] = {};
int n, m, curTime = 1;

// Builds the implication graph
// Input: vector of clauses
void buildGraph(vector<pair<int, int>> clauses) {
    for (auto [x, y] : clauses) {
        int negX = (negX > PAD ? x - PAD : x + PAD),
            negY = (negY > PAD ? y - PAD : y + PAD);
        G[negX].emplace_back(y);
        G[negY].emplace_back(x);
        GT[y].emplace_back(negX);
        GT[x].emplace_back(negY);
    }
}

// Kosaraju's Algorithm for finding SCCs
void findOutTimeDfs(int src) {
    if (out[src])
        return;
    out[src] = 1;   // mark visited
    for (auto &i : G[src]) {
        findOutTimeDfs(i);
    }
    out[src] = curTime++;
}

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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}