#include "bits/stdc++.h"
using namespace std;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define code ios_base::sync_with_stdio(false);
#define by cin.tie(NULL);
#define krishna cout.tie(NULL);
using ll=int;
using lld=long double;
using ull=unsigned long long;
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
class MoAlgo{
    // {BlockId, R}, {L, index}
    vector<pair<pll,pll>>queries;
    vll a;
    ll L,R,n,q,blockedSize;
    /*
      Keep more variables and Container According to need
    */
    public:
      MoAlgo(vll arr,vector<pair<pll,ll>> quer){
        // set iniitial window
        L=1,R=1;
        n=arr.size()-1;// 1 based
         a=arr;
         blockedSize=ceil(sqrt(n));
         q=quer.size();
         for(int i=0;i<q;i++){
            ll l=quer[i].ff.ff,r=quer[i].ff.ss,idx=quer[i].ss;
            ll currentBlockedID=(l-1)/blockedSize; // l-1 due to 1 based index
            queries.push_back({{currentBlockedID,r},{l,idx}});
         }
         /*
           do more initilization according to querys
         */
        }

    void add(int pos){
        // write the add position logic according to query
    }
    void remove(int pos){
       // write the remove position logic according to query
    }

    vll process(){
        sort(queries.begin(),queries.end());
        // change the Structure of ans according to need
        vll ans(q,0);
       L=1,R=1;
       add(1);
       for(int i=0;i<q;i++){
          auto it=queries[i];
          ll l=it.ss.ff;
          ll r=it.ff.ss;
          ll idx=it.ss.ss;
          while(R<r) add(++R);
          while(R>r) remove(R--);
          while(L<l) remove(L++);
          while(L>l) add(--L);
          //update your ans[idx] here
       }
       return ans;
    }
      
};
void solve(){
    // 1 based mo's algorithm
    ll n,q;cin>>n>>q;
    vll a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<pair<pll,ll>>queries;
    for(int i=0;i<q;i++){
        ll l,r;cin>>l>>r;
        queries.pb({{l,r},i});
    }
    MoAlgo ma(a,queries);
    vll ans=ma.process();
   cout<<ans<<"\n";
}
signed main(){
    #ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif
    code by krishna
    int t;cin>>t;
    while(t--){
        solve();
    }
}