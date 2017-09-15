#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

class Solution{
public:
	int lengthLongestPath(string input){
		vector<int> level(100);
		int le=1,count=0;
		bool isFile=false;
		int maxLength=0;
		for(int i=0;i<input.size();++i){
            //dip into which level of the files system
			while(input[i]=='\t'){
				le++;
				i++;
			}
            //seek until meet the end
			while(input[i]!='\n'&&i<input.size()){
				if(input[i]=='.')
					isFile=true;
				count++;
				i++;
			}
			if(isFile){
				maxLength=max(level[le-1]+count,maxLength);
			}else{
				level[le]=level[le-1]+count+1;// add 1 since we need count '\'
			}
            //reset
			count=0;
			le=1;
			isFile=false;

		}
		return maxLength;
	}
};

int main(){
	string test="dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	Solution s;
	cout<<s.lengthLongestPath(test)<<endl;

	return 0;
}
