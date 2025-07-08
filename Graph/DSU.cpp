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
    void UnionBySize(int a,int b){
        a=findSet(a);
        b=findSet(b);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            par[b]=a;
            sz[a]+=sz[b];
            cc--;
        }
    }
};