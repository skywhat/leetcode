#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        int maxArea=0;
        vector<int> heights(n+1,0);
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]=='0')
                    heights[j]=0;
                else
                    heights[j]++;
            }
            maxArea=max(maxArea,maxHist(heights));
        }
        return maxArea;
    }
    int maxHist(const vector<int>& heights){
        stack<int> s;
        int h,width,maxArea=0;
        for(int i=0;i<heights.size();){
            if(s.empty()||heights[s.top()]<=heights[i]){
                s.push(i);
                i++;
            }
            else{
                h=heights[s.top()];
                s.pop();
                if(s.empty()){
                    width=i;
                }
                else{
                    width=i-s.top()-1;
                }
                maxArea=max(width*h,maxArea);
            }
        }
        return maxArea;
    }
};

int main(){
}
