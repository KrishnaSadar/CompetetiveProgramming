#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
signed main(){
    ll n;cin>>n;
    ll m;cin>>m;
 
    vector<vector<ll>>adj(n+1);
    for(int i=2;i<=n;i++){
       ll x;cin>>x;
       adj[i].pb(x);
       adj[x].pb(i);
    }
 
    vector<ll> subT(n+1,0),parent(n+1,0),depth(n+1,0),heavy(n+1,0),head(n+1,0),pos(n+1,0);
    ll idx=0;
    auto dfs=[&](auto&& dfs,ll u, ll p)->void{
         parent[u]=p;
         
        for(auto it:adj[u]){
            if(it==p) continue;
            depth[it]=depth[u]+1;
            dfs(dfs,it,u);
            subT[u]+=subT[it];
            if(subT[it]>subT[heavy[u]]) heavy[u]=it;
        }
        subT[u]++;
    };
    auto dfsHLD=[&](auto&& dfsHLD,ll u,ll c,ll p)->void{
        head[u]=c;
        pos[u]=idx++;
        if(heavy[u]!=0) dfsHLD(dfsHLD,heavy[u],c,u);
        for(auto it:adj[u]){
            if(it==p||it==heavy[u]) continue;
            dfsHLD(dfsHLD,it,it,u);
        }
    };
    dfs(dfs,1,0);
    dfsHLD(dfsHLD,1,1,0);
 
    auto lca=[&](ll a,ll b){
        while(head[a]!=head[b]){
            if(depth[head[a]]<depth[head[b]]) swap(a,b);
            a=parent[head[a]];
        }
        if(depth[a]<depth[b]) swap(a,b);
        return b;
    };
    for(int i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
 
 
}