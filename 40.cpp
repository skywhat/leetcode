class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());
        combine(candidates,target,res,tmp,0);
        return res;
    }
    void combine(vector<int>& candidates,int target,vector<vector<int>>& res,vector<int>& tmp,int pos){
        if(target<0)
            return;
        if(target==0){
            res.push_back(tmp);
            return;
        }
        for(int i=pos;i<candidates.size();){
            tmp.push_back(candidates[i]);
            combine(candidates,target-candidates[i],res,tmp,i+1);
            tmp.pop_back();
            int cnt=0;
            while(i+cnt<candidates.size()&&candidates[i+cnt]==candidates[i])
                cnt++;
            i+=cnt;
        }
    }
    
};
