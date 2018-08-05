#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char,int> rows;
    string first_row = "qwertyuiopQWERTYUIOP";
    string second_row = "asdfghjklASDFGHJKL";
    string third_row = "zxcvbnmZXCVBNM";
public:
    Solution(){
        for(size_t i = 0; i< first_row.size(); ++i){
            rows[first_row[i]] = 1;
        }
        for(size_t i = 0; i< second_row.size(); ++i){
            rows[second_row[i]] = 2;
        }
        for(size_t i = 0; i< third_row.size(); ++i){
            rows[third_row[i]] = 3;
        }
    }
    
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        
        for(auto word: words){
            if(is_using_alphabet_on_one_row(word)){
                res.push_back(word);
            }
        }

        return res;
    }
    
    bool is_using_alphabet_on_one_row(string s){
        if(s.empty()){
            return true;
        }
        
        int row_label = rows[s[0]];
        for(int i = 1; i< s.size(); ++i){
            if(rows[s[i]] != row_label){
                return false;
            }
        }
        
        return true;
    }
};

int main(){
	Solution s;
	vector<string> test = {"Hello", "Alaska", "Dad", "Peace"};
	vector<string> expect = {"Alaska", "Dad"};

	cout<<(s.findWords(test) == expect) <<endl;

	return 0;
}
