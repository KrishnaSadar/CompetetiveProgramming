#include "bits/stdc++.h"
using namespace std;
//shortest path, positive weights
vector<long long> dijkstra(int n, int start, vector<vector<pair<int,int>>>& adj) {
    const long long INF = 1e18;
    vector<long long> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
