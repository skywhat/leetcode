#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution{
public:
	int ladderLength(string beginWord,string endWord,vector<string>& wordList){
		unordered_set<string> w(wordList.begin(),wordList.end());
		queue<string> toVisit;
		int dist=2;
		addNextWord(w,beginWord,toVisit);
		while(!toVisit.empty()){
			size_t size=toVisit.size();
			while(size--){
				string temp=toVisit.front();
				if(temp==endWord)
					return dist;
				toVisit.pop();
				addNextWord(w,temp,toVisit);
			}
			dist++;
		}
		return 0;
	}

	void addNextWord(unordered_set<string>& w,string beginWord,queue<string>& toVisit){
		for(size_t i=0;i<beginWord.size();++i){
			char backup=beginWord[i];
			for(char x='a';x<='z';++x){
				beginWord[i]=x;
				auto it=w.find(beginWord);
				if(it!=w.end()){
					toVisit.push(beginWord);
					w.erase(it);
				}
			}
			beginWord[i]=backup;
		}
	}

};	

int main(){
	string beginWord="hit";
	string endWord="cog";
	vector<string> wordList={"hot","dot","dog","lot","log","cog"};
	Solution s;
	cout<<s.ladderLength(beginWord,endWord,wordList)<<endl;

	return 0;
}


