#include<iostream>
#include<vector>
#include<unordered_map>
class Solution{
public:
	int leastBricks(vector<vector<int>>& wall){
		if(wall.size()==0)
			return 0;
		unordered_map<int,int> m;
		for(auto row:wall){
			int sum=0;
			for(int i=0;i+1<row.size();++i){
				sum+=row[i];
				m[sum]++;
			}
		}
		int height=wall.size();
		int maxEdge=0;
		for(auto it=m.begin();it!=m.end();++it){
			maxEdge=max(maxEdge,it->second);
		}
		return height-maxEdge;
	}
};

//considering if the wall has a pretty long width. we can scan from top to bottom. O(h) space complexity.
class Solution2 {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if(wall.size()==0)
            return 0;
        int width=0;
        for(auto b:wall[0])
            width+=b;
        vector<int> res(wall.size(),0);
        vector<int> index(wall.size(),1);
        for(int i=0;i<wall.size();++i){
            res[i]=wall[i][0];
        }
        int min=res[0];
        int maxCount=0;
        while(true){
            int count=0;
            for(int i=0;i<res.size();++i){
                if(res[i]<min)
                    min=res[i];
            }
            if(min==width)
                break;
            for(int i=0;i<res.size();++i){
                if(min<width&&min==res[i]){
                    count++;
                    res[i]+=wall[i][index[i]++];
                }
            }
            min=res[0];
            maxCount=max(maxCount,count);
        }
        return wall.size()-maxCount;
    }
};

int main(){

}
