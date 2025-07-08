#include "bits/stdc++.h"
using namespace std;
#define ll long long 
vector<ll>Computelps(string s){
   ll m=s.size();
   vector<ll>ans(m,0);
   ll i=1,len=0;
   while(i<m){
      if(s[i]==s[len]){
        len++;
        ans[i]=len;
        i++;
      }else{
         if(len>0) len=ans[len-1];
         else {ans[i]=0;i++;}
      }
   }
   return ans;

}
vector<ll>KMP(string s,string p){
    ll n=s.size(),m=p.size();
    vector<ll>lps=Computelps(p);
    ll i=0,j=0;
    vector<ll>pos;
    while(i<n){
        if(s[i]==p[j]){
            i++;
            j++;
        }
        if(j==m){
            pos.push_back(i-j);
            j=lps[j-1];
        }else if(i<n&&s[i]!=p[j]){
            if(j>0) j=lps[j-1];
            else i++;
        }
    }
    return pos;

}

signed main(){
    string s,t;
    cin>>s;cin>>t;
   vector<ll>ans=KMP(s,t);
   for(auto it:ans) cout<<it<<" ";
   cout<<"\n";
}