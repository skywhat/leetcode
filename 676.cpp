/*
 Implement a magic directory with buildDict, and search methods.
 
 For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.
 
 For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.
 
 Example 1:
 Input: buildDict(["hello", "leetcode"]), Output: Null
 Input: search("hello"), Output: False
 Input: search("hhllo"), Output: True
 Input: search("hell"), Output: False
 Input: search("leetcoded"), Output: False
 Note:
 You may assume that all the inputs are consist of lowercase letters a-z.
 For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
 Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.
 */
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<unordered_map>

using namespace std;

class MagicDictionary {
private:
    unordered_map<string,set<pair<int,char>>> magicDict;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto word:dict){
            for(int i=0;i<word.size();++i){
                string temp=word.substr(0,i)+word.substr(i+1);
                magicDict[temp].insert(make_pair(i,word[i]));
            }
        }
        //stdout
        for(auto it=magicDict.begin();it!=magicDict.end();++it){
            cout<<it->first<<" ";
            for(auto i:it->second)
            cout<<i.first<<" "<<i.second<<" ";
            cout<<endl;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(int i=0;i<word.size();++i){
            string temp=word.substr(0,i)+word.substr(i+1);
            for(auto elem:magicDict[temp]){
                if(elem.first==i&&elem.second!=word[i])
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

int main(){
	MagicDictionary obj;
	vector<string> dict={"hello","leetcode"};
	obj.buildDict(dict);
	vector<string> test={"hello","hhllo","hell","leetcoded"};
	cout<<"search result:"<<endl;
	for(auto word:test){
		cout<<word<<" "<<obj.search(word)<<endl;
	}	

	return 0;
}


