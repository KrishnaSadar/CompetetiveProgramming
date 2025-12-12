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
struct Point{
    ll x,y;
    Point():x(0),y(0){}
    Point(ll _x,ll _y):x(_x),y(_y){}
    bool operator ==(const Point& other) const{
        return x==other.x&&y==other.y;
    }
    bool operator <(const Point& other) const{
        if(x!=other.x) return x<other.x;
        return y<other.y;
    }
};
ll cross_product(const Point& A,const Point& B,const Point& C){
    /*
    cross(A, B, C) tells you how the angle turns when you go A → B → C.
    If cross > 0 → left turn (counter-clockwise)
    If cross < 0 → right turn (clockwise)
    If cross = 0 → collinear
    */
    return (B.x - A.x)*(C.y - A.y)-(B.y - A.y)*(C.x - A.x);
}
long long dot_product(const Point& A, const Point& B, const Point& C) {
    // computes (B - A) · (C - A)
    return (B.x - A.x) * (C.x - A.x)
         + (B.y - A.y) * (C.y - A.y);
}
long double dist_origin_to_segment(const Point &A, const Point &B) {
    // vector AB
    long double abx = (long double)B.x - (long double)A.x;
    long double aby = (long double)B.y - (long double)A.y;

    // dot1 = (B-A) · (O-A)  where O=(0,0)
    // = (B.x-A.x)*(0-A.x) + (B.y-A.y)*(0-A.y)
    long long dot1 = (B.x - A.x) * (-A.x) + (B.y - A.y) * (-A.y);
    if (dot1 <= 0) {
        // projection is behind A -> closest is A
        return sqrtl((long double)A.x * A.x + (long double)A.y * A.y);
    }

    // dot2 = (A-B) · (O-B)
    long long dot2 = (A.x - B.x) * (-B.x) + (A.y - B.y) * (-B.y);
    if (dot2 <= 0) {
        // projection is beyond B -> closest is B
        return sqrtl((long double)B.x * B.x + (long double)B.y * B.y);
    }

    // Otherwise projection falls inside segment -> perpendicular distance
    long long cr = cross_product(A, B, Point(0,0)); // this is an integer
    long double area = fabsl((long double)cr); // |cross|
    long double lenAB = sqrtl(abx * abx + aby * aby);
    return area / lenAB;
}
vector<Point> ConvexHullAndrowChain(vector<Point> pts) {
    sort(pts);
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    int n = pts.size();
    if (n <= 1) return pts;
    vector<Point> lower, upper;
    // Build lower hull
    for (int i = 0; i < n; ++i) {
        const Point &p = pts[i];
        while (lower.size() >= 2 &&
               cross_product(lower[lower.size()-2], lower[lower.size()-1], p) <= 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }

    // Build upper hull
    for (int i = n - 1; i >= 0; --i) {
        const Point &p = pts[i];
        while (upper.size()>=2&&cross_product(upper[upper.size()-2], upper[upper.size()-1], p) <= 0) {
            upper.pop_back();
        }
        upper.push_back(p);
    } 
    vector<Point> hull = lower;
    for (int i = 1; i + 1 < (int)upper.size(); ++i) {
        hull.push_back(upper[i]);
    }

    return hull; // CCW order
}
long double segment_area(long double r, long double d) {
    long double theta = acosl(d / r); // half-angle
    return r*r * theta - d * sqrtl(r*r - d*d);
}
long double compute_area(const vector<Point> &hull,const lld& r) {
    int m = hull.size();
     lld best = 0.0L;
    
    for (int i = 0; i < m; ++i) {
        const Point &A = hull[i];
        const Point &B = hull[(i + 1) % m];
        long double d = dist_origin_to_segment(A, B);
        if (d<=r) best = max(best, segment_area(r, d));
    }
    return best;
}
 
void solve(){
    ll n;cin>>n;
    lld r;cin>>r;
    vector<Point>a(n);
    for(int i=0;i<n;i++) cin>>a[i].x>>a[i].y;
    vector<Point>hull=ConvexHullAndrowChain(a);
   for(auto [x,y]:hull){
      cout<<x<<" "<<y<<"\n";
   }
}
