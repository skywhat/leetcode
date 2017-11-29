#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;//all the paths
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<vector<string>> paths;
        paths.push({beginWord});
        unordered_set<string> word;
        int level=1,minLevel=INT_MAX;

        while(!paths.empty()){
            auto cur=paths.front();
            paths.pop();
            while(cur.size()>level){
                for(auto&& w:word){
                    dict.erase(w);
                }
                level=cur.size();
                if(level>minLevel)//prune the search tree
                    break;
            }
            string last=cur.back();
            for(int i=0;i<last.size();++i){
                char x=last[i];
                for(char ch='a';ch<='z';++ch){
                    last[i]=ch;
                    if(dict.count(last)){
                        vector<string> next=cur;
                        word.insert(last);
                        next.push_back(last);
                        if(last==endWord){
                            res.push_back(next);
                            minLevel=level;
                        }
                        else
                            paths.push(next);
                    }
                }
                last[i]=x;
            }
        }
        return res;
    }
};

int main(){
}
