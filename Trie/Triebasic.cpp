
#include "bits/stdc++.h"
using namespace std;
struct Node{
    Node* a[26];
    int prefixcnt=0;
    int wordcnt=0;
};
 
class Trie{
    private:
   Node* root;    
    public:

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