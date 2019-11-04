#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	vector<int> lexicalOrder(int n){
		vector<int> res;
		res.reserve(n);
		for(int i=1;i<=n&&i<=9;++i){
			res.push_back(i);
			helper(n,i,res);
		}
		return res;
	}

	void helper(const int& n,int prefix,vector<int>& res){
		int num=prefix*10;
		for(int i=0;i<=9;i++){
			if(num<=n){
				res.push_back(num);
				helper(n,num,res);
				num++;
			}
			else
				return;
		}
	}
};

class Solution1{
public:
	vector<int> lexicalOrder(int n){
		vector<int> res(n,0);
		int curr=1;
		for(int i=0;i<res.size();++i){
			res[i]=curr;
			if(curr*10<=n){
				curr*=10;
			}
			else{
				if(curr>=n){
					curr/=10;
				}
				curr++;
				while(curr%10==0)
					curr/=10;
			}
		}
		return res;
	}
};

int main(){
	Solution1 s;
	int n=192;
	vector<int> test=s.lexicalOrder(n);
	for(auto t:test){
		cout<<t<<endl;
	}
	return 0;
}
