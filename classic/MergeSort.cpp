/*
 * a merge sort works as follows:
 * 1. Divide the unsorted list into n sublists, each containing 1 element is considered sorted
 * 2. Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.
 * */
#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

class Solution{
public:
	void mergesort(vector<int>& num,int l,int r){
		if(l<r){
			int m=l+(r-l)/2;
			mergesort(num,l,m);
			mergesort(num,m+1,r);
			merge(num,l,m,r);
			copy(num.begin(),num.end(),ostream_iterator<int>(cout,", "));
			cout<<endl;
		}
	}
	void merge(vector<int>& num,int l,int m,int r){
		int size1=m-l+1;
		int size2=r-m;
		vector<int> left(num.begin()+l,num.begin()+m+1);	
		vector<int> right(num.begin()+m+1,num.begin()+r+1);
		int i=0,j=0,k=l;
		while(i<size1&&j<size2){
			if(left[i]<=right[j]){
				num[k++]=left[i++];
			}
			else{
				num[k++]=right[j++];
			}
		}
		while(i<size1)	{
			num[k++]=left[i++];
		}
		while(j<size2){
			num[k++]=right[j++];
		}

	}
};


int main(){
	Solution s;
	vector<int> num={2,1,12,11,19,17,8,13,5,6,7};
	s.mergesort(num,0,num.size()-1);
	
	copy(num.begin(),num.end(),ostream_iterator<int>(cout,", "));
	cout<<endl;
	return 0;
}
