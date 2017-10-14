#include<iostream>
#include<vector>

//Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution{
public:
	int firstBadVersion(int n){
		int left=1,right=n;
		while(left<right){
			//(low+high)/2 it may cause time limit exceed due to overflow.
			int mid=left+(right-left)/2;
			if(isBadVersion(mid))
				right=mid-1;
			else
				left=mid+1;
		}
		if(isBadVersion(left))
			return left;
		else
			return left+1;
	}
};	

class Solution2 {
public:
    int firstBadVersion(int n) {
        int left=1,right=n;
        while(left<right){
            int mid=left+(right-left)/2;
            if(isBadVersion(mid))
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};

int main(){

}
