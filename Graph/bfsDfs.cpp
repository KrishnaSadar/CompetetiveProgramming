#include "bits/stdc++.h"
using namespace std;

void bfs(int start, vector<vector<int>>& adj, vector<int>& dist) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v])
            dfs(v, adj, visited);
    }
}
