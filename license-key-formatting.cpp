class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		int total = 0;
		string res;
		for (auto s : S)
			if (s != '-')
				total++;
		int first_length = total%K;
		int round = total / K;
		int pos = 0;
		if (first_length) {
			for (int i = 1; i <= first_length; ++i) {
				while (S[pos] == '-')
					pos++;
				res += toupper(S[pos++]);
			}
			if (round>0)
				res += '-';
		}
		while (pos < S.size()) {
			for (int i = 1; i <= K&&pos < S.size(); ++i) {
				while (S[pos] == '-')
					pos++;
				res += toupper(S[pos++]);
			}
			round--;
			if(round>0)
				res += '-';
		}
		return res;
	}
};