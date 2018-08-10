class Solution {
public:
    string longestWord(vector<string>& words) {
        string res;
        unordered_set<string> words_set;
        sort(words.begin(), words.end());
        
        for(string w: words){
            if(w.size() == 1 || words_set.count(w.substr(0, w.size()-1))){
                words_set.insert(w);
                if(w.size() > res.size()){
                    res = w;
                }
            }
        }
        
        return res;
    }
};
