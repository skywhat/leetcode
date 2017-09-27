#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
public:
	vector<string> fizzBuzz(int n){
		vector<string> res;
		for(int i=1;i<=n;++i){
			if(i%15==0)
				res.push_back("FizzBuzz");
			else if(i%3==0)
				res.push_back("Fizz");
			else if(i%5==0)
				res.push_back("Buzz");
			else
				res.push_back(to_string(i));
		}
		return res;
	}
};	

int main(){
	Solution s;
	int n=15;
	vector<string> res=s.fizzBuzz(n);
	for(auto r:res){
		cout<<r<<endl;
	}

	return 0;
}
