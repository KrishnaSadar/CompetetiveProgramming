#include "bits/stdc++.h"
using namespace std;

struct Node{
    Node* a[2];
    bool f=false;
};
bool isset(int n,int i){
    return (1<<i)&n;
}
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
   
   void insert(int n){
    Node* ref=root;
      for(int i=30;i>=0;i--){
         if(ref->a[isset(n,i)]==NULL){
            ref->a[isset(n,i)]=new Node();
         }
         ref=ref->a[isset(n,i)];
      }
      ref->f=true;
   }
   int xxor(int n){
      Node* ref=root;
      int ans=0;
      if(ref->a[0]==NULL&&ref->a[1]==NULL) return -1;
      for(int i=30;i>=0;i--){
        bool k=isset(n,i);
        
        if(ref->a[!k]==NULL){
            ans+=0;
            ref=ref->a[k];
        }else{
            ans+=(1<<i);
            ref=ref->a[!k];
        }
      }
     return ans;
   }

};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    Trie* t=new Trie();
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<int>ans(queries.size(),-1);
    vector<pair<int,pair<int,int>>>q;
   for(int i=0;i<queries.size();i++){
      q.push_back({queries[i][1],{queries[i][0],i}});
   }
    sort(q.begin(),q.end());
    int i=0;
    for(auto it:q){
        while(i<n&&arr[i]<=it.first){
            t->insert(arr[i]);
            i++;
        }
        ans[it.second.second]=(t->xxor(it.second.first));
    }
    return ans;
}