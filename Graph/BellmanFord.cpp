#include "bits/stdc++.h"
using namespace std;

bool bellman_ford(int n, int start, vector<tuple<int,int,int>>& edges, vector<long long>& dist) {
    const long long INF = 1e18;
    dist.assign(n, INF);
    dist[start] = 0;
    for (int i = 0; i < n-1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] < INF && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }
    for (auto [u, v, w] : edges) {
        if (dist[u] < INF && dist[v] > dist[u] + w)
            return true; // negative cycle
    }
    return false;
}
