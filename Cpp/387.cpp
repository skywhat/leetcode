class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> dict(128, 0);
        
        for(auto c: s){
            dict[c]++;
        }
        
        for(int i=0;i<s.size();++i){
            if(dict[s[i]] == 1){
                return i;
            }
        }
        
        return -1;
    }
};
