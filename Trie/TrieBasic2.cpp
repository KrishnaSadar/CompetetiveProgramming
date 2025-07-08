#include <bits/stdc++.h> 
using namespace std;
struct Node{
    Node* a[26];
    int prefixcnt=0;
    int wordcnt=0;
};
 
class Trie{
    public:
   Node* root;    
    

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            int ch=word[i]-'a';
            if(node->a[ch]==NULL){
                node->a[ch]=new Node();
                
            } 
                node=node->a[ch];
                node->prefixcnt++;
        }
        node->wordcnt++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            int ch=word[i]-'a';
            if(node->a[ch]==NULL){
                return 0;
            }else{
                node=node->a[ch];
            }
        }
        return node->wordcnt;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        int ans=0;
        for(int i=0;i<word.size();i++){
            int ch=word[i]-'a';
            if(node->a[ch]==NULL){
                return 0;
            }else{
                ans=node->prefixcnt;
                node=node->a[ch];
            }
        }
        return node->prefixcnt;
    }

    void erase(string &word){
        // Write your code here.
         Node* node=root;
        int ans=0;
        for(int i=0;i<word.size();i++){
            int ch=word[i]-'a';
            if(node->a[ch]==NULL){
                return;
            }else{
                node=node->a[ch];
            }
        }
        node=root;
        for(int i=0;i<word.size();i++){
            int ch=word[i]-'a';
            if(node->a[ch]==NULL){
                return;
            }else{
                node=node->a[ch];
                 node->prefixcnt--;
            }
        }
        node->wordcnt--;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    map<string,int>mp;
    Trie* t=new Trie();
  
    for(int i=0;i<n;i++) t->insert(a[i]);
    string ans="";
    for(int i=0;i<n;i++){
        string tmp="";
        bool isp=true;
        for(int j=0;j<a[i].size();j++){
            tmp+=a[i][j];
            if(t->countWordsEqualTo(tmp)<=0){
                isp=false;
                break;
            }
        }
        if(isp&&ans.size()<=tmp.size()){
            if(tmp.size()>ans.size()){
                ans=tmp;
            }else{
                ans=min(ans,tmp);
            }
        }

    }
    if(ans=="") return "None";
    return ans;

}