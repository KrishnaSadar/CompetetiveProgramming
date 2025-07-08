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
#define fr(i, st, end) for(int i = st; i <= end; i++)
#define frr(i, st, end) for(int i = st; i >= end; i--)
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define sz(x) ((int)(x).size());
#define all(x) (x).begin(), (x).end()
 
template<typename T1, typename T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) {
    return (istream >> p.first >> p.second);
}
 
template<typename T>
istream& operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}
 
template<typename T1, typename T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) {
    return (ostream << p.first << " " << p.second);
}
 
template<typename T>
ostream& operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}
 
struct Node {
    Node* child[26];
    Node* suffixlink;
    Node* outputlink;
    vector<int> idxs;
    bool visited;
    Node() : suffixlink(nullptr), outputlink(nullptr), visited(false) {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};
 
void buildTrie(Node* root, vector<string>& patterns) {
    for (int i = 0; i < patterns.size(); i++) {
        Node* cur = root;
        for (char c : patterns[i]) {
            int index = c - 'a';
            if (cur->child[index] == nullptr) {
                cur->child[index] = new Node();
            }
            cur = cur->child[index];
        }
        cur->idxs.push_back(i);
    }
}
 
void buildSuffixAndOutputLinks(Node* root) {
    queue<Node*> q;
    root->suffixlink = root;
    root->outputlink = nullptr;
 
    for (int i = 0; i < 26; i++) {
        if (root->child[i] != nullptr) {
            Node* childNode = root->child[i];
            childNode->suffixlink = root;
            if (childNode->suffixlink->idxs.empty()) {
                childNode->outputlink = childNode->suffixlink->outputlink;
            } else {
                childNode->outputlink = childNode->suffixlink;
            }
            q.push(childNode);
        }
    }
 
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            Node* child = cur->child[i];
            if (child == nullptr) continue;
 
            Node* tmp = cur->suffixlink;
            while (tmp != root && tmp->child[i] == nullptr) {
                tmp = tmp->suffixlink;
            }
            if (tmp->child[i] != nullptr) {
                child->suffixlink = tmp->child[i];
            } else {
                child->suffixlink = root;
            }
 
            if (child->suffixlink->idxs.empty()) {
                child->outputlink = child->suffixlink->outputlink;
            } else {
                child->outputlink = child->suffixlink;
            }
 
            q.push(child);
        }
    }
}
 
vector<int> searchPatterns(Node* root, string& s, int k) {
    vector<int> found(k, -1);
    Node* cur = root;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        while (cur != root && cur->child[c] == nullptr) {
            cur = cur->suffixlink;
        }
        if (cur->child[c] != nullptr) {
            cur = cur->child[c];
        }
        Node* temp = cur;
        while (temp != nullptr && !temp->visited) {
            for (int idx : temp->idxs) {
                found[idx] = i;
            }
            temp->visited = true;
            temp = temp->outputlink;
        }
    }
    return found;
}
 
void solve() {
    // first position where the pattern occur
    string s;
    cin >> s;
    ll n;
    cin >> n;
    vector<string> patterns(n);
    for (int i = 0; i < n; i++) {
        cin >> patterns[i];
    }
    Node* root = new Node();
    buildTrie(root, patterns);
    buildSuffixAndOutputLinks(root);
    vector<int> ans = searchPatterns(root, s, n);
    for (int i = 0; i < n; i++) {
       if(ans[i]<0){
        cout<<-1<<"\n";
       }else{
        cout<<ans[i]-patterns[i].size()+2<<"\n";
       }
    }
}
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    code by krishna
    solve();
    return 0;
}