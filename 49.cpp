#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs){
		vector<string> temp(strs.begin(),strs.end());
		for(auto& t:temp)
			sort(t.begin(),t.end());
		unordered_map<string,unordered_set<int>> m;
		for(int i=0;i<temp.size();++i)
			m[temp[i]].insert(i);
		vector<vector<string>> res(m.size());
		int row=0;
		for(auto& item:m){
			for(auto index:item.second)
				res[row].push_back(strs[index]);
			row++;
		}
		return res;
	}
};

int main(){
	vector<string> test={"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution s;
	vector<vector<string>> res=s.groupAnagrams(test);

	for(auto i:res){
		cout<<"[";
		for(auto j:i){
			cout<<j<<", ";
		}
		cout<<"]"<<endl;

	}

	return 0;

}

