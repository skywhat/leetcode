#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string charValue = "10101111111111111111111111";
    int getSpecialSubstring(string s, int k) {
        vector<int> m(128, 0);
        int i = 0, j = 0;
        int cnt = 0;
        int res = 0;
        while (j < s.size()) {
            if (charValue[s[j] - 'a'] == '0') {
                cnt++;
            }
            j++;
            if (cnt == k) {
                res = max(res, j - i);
            }
            while (cnt > k) {
                if (charValue[s[i] - 'a'] == '0') {
                    cnt--;
                }
                i++;
            }
        }

        return res;
    }
};


int main(){
    string test = "abcde";
    Solution s;
    int k = 1;
    cout << s.getSpecialSubstring(test, k) << endl;

    return 0;
}
