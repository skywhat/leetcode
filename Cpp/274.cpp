#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size=citations.size();
        vector<int> bucket(size+1,0);
        for(auto c:citations){
            if(c>=size)
                bucket[size]++;
            else
                bucket[c]++;
        }
        int sum=0;
        for(int i=size;i>=0;--i){
            sum+=bucket[i];
            if(i<=sum)
                return i;
        }
        return 0;
    }
};

int main(){

}
