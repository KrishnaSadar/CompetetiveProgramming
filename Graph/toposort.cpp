#include "bits/stdc++.h"
using namespace std;

vector<int> topo_sort(int n, vector<vector<int>>& adj) {
    vector<int> in_deg(n, 0), res;
    for (auto u = 0; u < n; u++)
        for (auto v : adj[u])
            in_deg[v]++;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (in_deg[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        res.push_back(u);
        for (auto v : adj[u]) {
            if (--in_deg[v] == 0)
                q.push(v);
        }
    }
    return res; // size == n → DAG; else → cycle exists
}

