#include<iostream>
#include<vector>

using namespace std;

bool knows(int a,int b);

class Solution{
public:
	int findCelebrity(int n){
		int candidate=0;
		for(int i=1;i<n;++i)
			if(knows(candidate,i))
				candidate=i;
		for(int i=0;i<candidate;++i)
			if(knows(candidate,i))
				return -1;
		for(int i=0;i<n;++i)
			if(!knows(i,candidate))
				return -1;
		return candidate;
	}
};


int main(){

}
