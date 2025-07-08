#include "bits/stdc++.h"
using namespace std;
class DisjointSet{
    public:
    vector<int>par,sz;
    int cc;
    DisjointSet(int n){
        par.resize(n);
        sz.assign(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        cc=n;
    }
    int findSet(int i){
        if(par[i]==i) return i;
        return par[i]=findSet(par[i]);
    }
    bool isSameSet(int a,int b){
        return findSet(a)==findSet(b);
    }
    bool UnionBySize(int a,int b){
        a=findSet(a);
        b=findSet(b);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            par[b]=a;
            sz[a]+=sz[b];
            cc--;
            return true;
        }
        return false;
    }
};

long long kruskal(int n, vector<tuple<int,int,int>>& edges) {
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return get<2>(a) < get<2>(b);
    });
    DisjointSet dsu(n);
    long long mst_weight = 0;
    for (auto [u, v, w] : edges) {
        if (dsu.UnionBySize(u, v))
            mst_weight += w;
    }
    return mst_weight;
}
