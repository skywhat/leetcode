class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        combine(candidates,0,tmp,target,res);
        return res;
    }
    void combine(vector<int>& candidates,int pos,vector<int>& tmp,int target,vector<vector<int>>& res){
        if(target<0)
            return;
        if(target==0){
            res.push_back(tmp);
            return;
        }
        for(int i=pos;i<candidates.size();++i){
            tmp.push_back(candidates[i]);
            combine(candidates,i,tmp,target-candidates[i],res);
            tmp.pop_back();
        }
    }
};
