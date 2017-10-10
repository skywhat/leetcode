#include<iostream>
#include<vector>
#include<string>

using namespace std;

class WordDictionary {
private:
    struct TrieNode{
        TrieNode* next[26];
        bool have;
        TrieNode(bool h=false):have(h){
            for(int i=0;i<26;++i)
                next[i]=nullptr;
        }
    };
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur=root;
        size_t i=0;
        while(i<word.size()){
            if(cur->next[word[i]-'a']==nullptr){
                cur->next[word[i]-'a']=new TrieNode();
            }
            cur=cur->next[word[i++]-'a'];
        }
        cur->have=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode* cur=root;
        return search(0,word,cur);
    }
    bool search(int i,const string& word,TrieNode* cur){
        while(i<word.size()&&cur){
            if(word[i]=='.'){
                for(int ind=0;ind<26;++ind)
                    if(search(i+1,word,cur->next[ind]))
                        return true;
                return false;
                /* also:
                 bool have=false;
                 for(int ind=0;ind<26;++ind)
                     have=have||search(i+1,word,cur->next[ind]);
                 return have;
                 */
                
            }
            else
                cur=cur->next[word[i]-'a'];
            i++;
        }
        return cur&&cur->have;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main(){

}
