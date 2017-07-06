#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProduct(vector<string>& words) {
		int maxValue = 0;
		vector<int> v(words.size(), 0);
		for (int i = 0; i < words.size(); ++i) {
			for (auto w : words[i]) {
				v[i] |= (1 << (w - 'a'));
			}
		}
		for (int i = 0; i < v.size(); ++i) {
			for (int j = i + 1; j < v.size(); ++j) {
				if (!(v[i] & v[j])) {
					maxValue = max(int(words[i].size()*words[j].size()), maxValue);
				}
			}
		}
		return maxValue;
	}
};

int main() {
	vector<string> test = { "abcw","baz","foo","bar","xtfn","abcdef" };
	Solution s;
	cout << s.maxProduct(test) << endl;
	return 0;
}


