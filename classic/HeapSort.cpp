#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
	void sift(vector<int> &num,int i,int n){
		while(i<n/2){
			int j=i*2+1;
			int k=j+1;
			int lg;
			if(k<n&&num[k]>=num[j]){
				lg=k;
			}
			else{
				lg=j;
			}
			if(num[i]>=num[lg])
				return;
			swap(num[i],num[lg]);
			i=lg;
		}
	}
	void heapify(vector<int> &num,int n){
		int i=n/2-1;
		while(i>=0){
			sift(num,i,n);
			i--;
		}
	}

	void heapsort(vector<int> &num){
		heapify(num,num.size());
		int i=num.size()-1;
		while(i>=1){
			swap(num[0],num[i]);
			i--;
			sift(num,0,i+1);
		}
	}
};

int main(){
	Solution s;
	vector<int> num={-5,12,8,0,21,1,2};

	s.heapsort(num);
	copy(num.begin(),num.end(),ostream_iterator<int>(cout,", "));
	cout<<endl;

	return 0;
}



/*
 * the heapsort function first converts num into a heap, then applies sift n-1 times. The swap-sift loop therefore requires O(lg n) steps.
 * heapify actually runs in O(n) time.
 * */
