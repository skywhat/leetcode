//Text justification

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
  		vector<string> res;
  		for(int i=0,j;i<words.size();i=j){
			int width=0;
			for(j=i;j<words.size()&&width+j-i+words[j].size()<=maxWidth;++j){
				width+=words[j].size();
			}
			string tmp=words[i];
			int space=1,extra=0;
			if(j-i>1&&j<words.size()){
				//we have j-i strings, then need j-i-1 space
				space=(maxWidth-width)/(j-i-1);
				extra=(maxWidth-width)%(j-i-1);
			}
			for(int k=i+1;k<j;++k){
				tmp+=string(space,' ');
				if(extra-->0){
					tmp+=" ";
				}
				tmp+=words[k];
			}
			//add the remaining space.
			tmp+=string(maxWidth-tmp.size(),' ');
			res.push_back(tmp);
		}		
		return res;
    }
};

int main(){

}
