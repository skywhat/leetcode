#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size=citations.size();
        int left=0,right=size-1;
        int res=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(citations[mid]>=size-mid){
                res=size-mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return res;
    }
};


class Solution2 {
public:
    int hIndex(vector<int>& citations) {
        int ind=citations.size();
        int res=0;
        for(int i=ind-1;i>=0;--i){
            if(citations[i]>=ind-i)
                res=ind-i;
            else
                break;
        }
        return res;
    }
};

/*
 0 0 4 4
 i  0 1 2 3
 
 */

