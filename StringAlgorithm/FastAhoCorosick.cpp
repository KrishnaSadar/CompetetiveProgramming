#include "bits/stdc++.h"
using namespace std;
 
#define code ios_base::sync_with_stdio(false);
#define by cin.tie(NULL);
#define krishna cout.tie(NULL);
 
using ll = long long;
using lld = long double;
using ull = unsigned long long;
 
const lld pi = 3.1415926535;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
 
typedef pair<int, int> p;
typedef vector<int> vec;
typedef vector<p> vecp;
typedef unordered_map<int, int> um;
typedef map<int, int> m;
 
#define ff first
#define ss second
#define pb push_back
#define cut pop_back
#define fr(i, st, end) for(int i = st; i <= end; i++)
#define frr(i, st, end) for(int i = st; i >= end; i--)
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define sort(x) sort(x.begin(), x.end());
#define rsort(x) sort(x.begin(), x.end(), greater<int>());
#define sz(x) ((int)(x).size());
#define all(x) (x).begin(), (x).end()
 
// ----------------- FAST AHOCORASICK -----------------
const int ALPHA = 26;
const int MAXNODES = 500000 + 5;  

int nxt[MAXNODES][ALPHA];
int linkS[MAXNODES];
ll cntNode[MAXNODES];
vector<int> adjSL[MAXNODES];
vector<int> patEnd;             
int nodes = 1;

void build_trie(const vector<string>& P) {
    // clear
    for(int i = 0; i < nodes; i++){
        memset(nxt[i], 0, sizeof nxt[i]);
        cntNode[i] = 0;
        adjSL[i].clear();
    }
    nodes = 1;
    patEnd.clear();
    patEnd.reserve(P.size());
    // insert
    for(auto &pat: P){
        int u = 0;
        for(char ch: pat){
            int c = ch - 'a';
            if(!nxt[u][c]) nxt[u][c] = nodes++;
            u = nxt[u][c];
        }
        patEnd.pb(u);
    }
}

vector<int> bfsOrder;
void build_links(){
    queue<int> q;
    linkS[0] = 0;
    // first layer
    for(int c = 0; c < ALPHA; c++){
        int v = nxt[0][c];
        if(v){
            linkS[v] = 0;
            q.push(v);
        }
    }
    // BFS
    while(!q.empty()){
        int u = q.front(); q.pop();
        bfsOrder.pb(u);
        for(int c = 0; c < ALPHA; c++){
            int v = nxt[u][c];
            if(!v) continue;
            int j = linkS[u];
            while(j && !nxt[j][c]) j = linkS[j];
            if(nxt[j][c]) j = nxt[j][c];
            linkS[v] = j;
            q.push(v);
        }
    } 
    for(int u: bfsOrder){
        adjSL[ linkS[u] ].pb(u);
    }
}

void solve(){
    string S; ll k;
    cin >> S >> k;
    vector<string> P(k);
    for(int i = 0; i < k; i++) cin >> P[i];
 
    build_trie(P);
    bfsOrder.clear();
    build_links();
  
    int u = 0;
    for(char ch: S){
        int c = ch - 'a';
        while(u && !nxt[u][c]) u = linkS[u];
        if(nxt[u][c]) u = nxt[u][c];
        cntNode[u]++;
    }
  
    for(int i = (int)bfsOrder.size()-1; i >= 0; i--){
        int v = bfsOrder[i];
        cntNode[ linkS[v] ] += cntNode[v];
    }
   // no of occurances of perticular pattern
    for(int i = 0; i < k; i++){
        cout << cntNode[ patEnd[i] ] << "\n";
    }
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    code by krishna
    solve();
    return 0;
}
