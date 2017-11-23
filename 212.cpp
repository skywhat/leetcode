#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    public:
    struct TrieNode{
        TrieNode* next[26];
        string word;
        TrieNode(string w=""):word(w){
            for(int i=0;i<26;++i)
            next[i]=nullptr;
        }
    };
    void buildTrie(vector<string>& words,TrieNode* root){
        for(auto&& word:words){
            TrieNode* cur=root;
            for(int i=0;i<word.size();++i){
                if(cur->next[word[i]-'a']==nullptr)
                cur->next[word[i]-'a']=new TrieNode();
                cur=cur->next[word[i]-'a'];
            }
            cur->word=word;
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root=new TrieNode();
        vector<string> res;
        buildTrie(words,root);
        const int m=board.size();
        const int n=board[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                dfs(root,board,res,i,j,m,n);
            }
        }
        return res;
    }
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(TrieNode* root,vector<vector<char>>& board,vector<string>& res,int i,int j,const int& m,const int& n){
        char x=board[i][j];
        if(x=='*')
        return;
        TrieNode* tmp=root->next[board[i][j]-'a'];
        if(tmp==nullptr)
        return;
        if(tmp->word!=""){//found one.
            res.push_back(root->next[board[i][j]-'a']->word);
            tmp->word="";//no duplicate.
            //no return, move forward.
        }
        board[i][j]='*';
        for(auto&& d:dir){
            int x=i+d[0];
            int y=j+d[1];
            if(x>=0&&x<m&&y>=0&&y<n)
            dfs(tmp,board,res,x,y,m,n);
        }
        board[i][j]=x;
        return;
    }
    
};

int main(){

}
