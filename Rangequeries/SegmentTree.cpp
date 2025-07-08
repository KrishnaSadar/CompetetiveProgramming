#include "bits/stdc++.h"
using namespace std;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define code ios_base::sync_with_stdio(false);
#define by cin.tie(NULL);
#define krishna cout.tie(NULL);
using ll=long long;
using lld=long double;
using ull=unsigned long long;
const lld pi=3.1415926535;
const ll INF=1e18;
const ll mod=1e9+7;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//stl containers
typedef pair<int,int> p;
typedef vector<int> vec;
typedef vector<p> vecp;
typedef vector<string> vs;
typedef unordered_map<int,int> um;
typedef map<int,int> m;
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define ff first
#define ss second
#define pb push_back
#define cut pop_back
#define fr(i,st,end) for(int i=st;i<=end;i++)
#define frr(i,st,end) for(int i=st;i>=end;i--)
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define sort(x) sort(x.begin(),x.end());
#define rsort(x) sort(x.begin(),x.end(),greater<int>());
#define sz(x) ((int)(x).size());
#define all(x) (x).begin(), (x).end()
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//operators overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v) cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll modMul(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//binary search section
int LB(vector<ll>arr,ll key){auto lower = lower_bound(arr.begin(), arr.end(), key); if (lower != arr.end()) {return lower - arr.begin(); } return -1; }
int UB(vector<ll>arr,ll key){auto upper = upper_bound(arr.begin(), arr.end(), key);if (upper != arr.begin()&&(upper-arr.begin())<arr.size()) {return upper - arr.begin();}return -1;}
bool checkerFunction(int x,vector<int>&arr){return true;}
int BSAns(int st,int end,vector<int>arr){int ans=-1;while(st<=end){int mid=st+(end-st)/2;if(checkerFunction(mid,arr)){ }else{}}return ans;}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//prefix suffix section 1 based
vector<int> buildPrefix(vector<int>&arr){vector<int>ans(arr.size(),0);for(int i=1;i<=arr.size();i++){ans[i]=arr[i]+ans[i-1];}return ans;}
vector<int> buildSuffix(vector<int>&arr){vector<int>ans(arr.size()+1,0);for(int i=arr.size()-1;i>=1;i--){ans[i]=ans[i+1]+arr[i];}return ans;}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
 कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥
 */
//1)Try Sample Test Cases
//2)Dry run on Each Sample Test Case
//3)Try Extreme test cases min and max
//A)Brute Force B)Math with optimization C) Math with implemention
class SegmentTree{
    public:
      vector<ll>a,b;
      ll n;
      SegmentTree(vll arr){
        n=arr.size()-1;
        b=arr;
        a.resize(4*n+1,0);
         build(1,n,1);
      }
      ll combine(ll a,ll b){
        return a+b;
      }
      void build(int st,int ed,int idx){
        if(st==ed){
            a[idx]=b[st];
            return;
        }
        int mid=(st+ed)/2;
        build(st,mid,idx*2);
        build(mid+1,ed,2*idx+1);
        a[idx]=combine(a[idx*2],a[idx*2+1]);
      }
      void rec(int st,int ed,int idx,int target_idx,int target_val){
         if(st==ed&&st==target_idx){
            a[idx]=target_val;
            return;
         }
         int mid=(st+ed)/2;
         if(mid>=target_idx){
            rec(st,mid,2*idx,target_idx,target_val);
         }else{
            rec(mid+1,ed,2*idx+1,target_idx,target_val);
         }
        a[idx]=combine(a[idx*2],a[idx*2+1]);
      }
       
      ll rec1(int st,int ed,int idx,int l,int r){
          if(ed<l||r<st) return 0;
          if(st>=l&&ed<=r) return a[idx];
          int mid=(st+ed)/2;
          ll a=rec1(st,mid,2*idx,l,r);
          ll b=rec1(mid+1,ed,2*idx+1,l,r);
          return combine(a,b);
      }
      
      void update(ll idx,ll val){
        rec(1,n,1,idx,val);
      }
      ll queries(ll l,ll r){
        return rec1(1,n,1,l,r);
      }
};
 
void solve(){
    ll n,q;
    cin>>n>>q;
    vll a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    SegmentTree sgt(a);
    while(q--){
        ll t;
        cin>>t;
        if(t==1){
            ll k,u;cin>>k>>u;
            sgt.update(k,u);
        }else{
            ll l,r;cin>>l>>r;
            cout<<sgt.queries(l,r)<<"\n";
        }
    }
 
}
signed main(){
    #ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif
    code by krishna
    solve();
}