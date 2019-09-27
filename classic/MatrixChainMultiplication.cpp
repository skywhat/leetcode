#include<iostream>
#include<vector>
#include<string>

using namespace std;

int MatrixChainOrder(vector<int>& m,int i,int j,int& call){
	call++;
	if(i==j)
		return 0;
	int minVal=INT_MAX;
	int count;
	for(int k=i;k<j;++k){
		count=MatrixChainOrder(m,i,k,call)+MatrixChainOrder(m,k+1,j,call)+m[i-1]*m[k]*m[j];
		if(count<minVal)
			minVal=count;
	}
	return minVal;
}

int main(){
	vector<int> test={1,2,3,4};
	int call=0;
	cout<<MatrixChainOrder(test,1,test.size()-1,call)<<endl;
	cout<<"call"<<call<<endl;
	return 0;
}
