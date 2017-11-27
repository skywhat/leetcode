class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        combine(res,tmp,1,k,n);
        return res;
    }
    void combine(vector<vector<int>>& res,vector<int>& tmp,int pos,const int& k,const int& n){
        if(tmp.size()==k){
            res.push_back(tmp);
            return;
        }
        for(int i=pos;i<=n;++i){
            tmp.push_back(i);
            combine(res,tmp,i+1,k,n);
            tmp.pop_back();
        }
    }
};
