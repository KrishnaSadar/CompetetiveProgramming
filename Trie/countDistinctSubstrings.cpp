#include <bits/stdc++.h> 
using namespace std;
struct Node{
    Node* a[26];
    int prefixcnt=0;
    int wordcnt=0;
};
 
class Trie{
    private:
  
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
    int traverseTrie(Node* node){
        int ans=0;
        for(int i=0;i<26;i++){
            if(node->a[i]!=NULL){
               ans+=traverseTrie(node->a[i]);
            }
        }
        return ans+(node->wordcnt>0);
    }
};


int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Trie* t=new Trie();
    for(int i=0;i<s.size();i++){
        string tmp="";
        for(int j=i;j>=0;j--){
            tmp=s[j]+tmp;
            //cout<<tmp<<"\n";
            t->insert(tmp);
        }
    }
    return t->traverseTrie(t->root)+1;

}