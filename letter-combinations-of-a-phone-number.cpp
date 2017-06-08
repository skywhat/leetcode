class Solution {
private:
	string mapping[10] = { "0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (!digits.empty())
			combine(res, "", digits);
		return res;
	}
	void combine(vector<string>& v, string s, string digits) {
		if (s.size() == digits.size()) {
			v.push_back(s);
			return;
		}
		int pos = s.size();
		for (auto x : mapping[digits[pos]-'0'])
			combine(v, s + x, digits);
	}
};