#include "bits/stdc++.h"
using namespace std;
#define ll long long 
vector<ll>Zfunction(string s){
    ll n=s.size();
    vector<ll>z(n,0);
    ll l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<r){
            z[i]=min(r-i,z[i-l]);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;

        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}

ll countDistinctSubstrings(string s){
    ll n=s.size();
    int ans=0;
    for(int i=0;i<n;i++){
        string suf=s.substr(i);
        vector<ll>z=Zfunction(suf);
        ll maxi=*max_element(z.begin(),z.end());
        ans+=(suf.size()-maxi);
    }
    return ans;

}

signed main(){
    string s;cin>>s;
   cout<<countDistinctSubstrings(s)<<"\n";
}