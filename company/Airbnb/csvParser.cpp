#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string parseCSV(string s) {
        vector<string> parts;
        string temp;
        bool inQuote = false;

        for (int i = 0; i < s.size(); ++i) {
            if (inQuote) {
                if (s[i] == '\"') {
                    if (i + 1 < s.size() && s[i + 1] == '\"') {
                        temp += '\"';
                        i++;
                    } else {
                        inQuote = false;
                    }
                } else {
                    temp += s[i];
                }
            } else {
                if (s[i] == '\"') {
                    inQuote = true;
                } else if (s[i] == ',') {
                    parts.push_back(temp);
                    temp = "";
                } else {
                    temp += s[i];
                }
            }
        }

        if (!temp.empty()) {
            parts.push_back(temp);
        }

        string res;
        for (int i = 0; i + 1 < parts.size(); ++i) {
            res += parts[i] + "|";
        }
        res += parts.back();
        return res;
    }
};

int main() {
    Solution s;

    string ss[] = {
        "John,Smith,john.smith@gmail.com,Los Angeles,1",
        "\"Alexandra \"\"Alex\"\"\",abc@mail.com,1 \"\"\"\"\"Alex Alex\"\"\"\"\"",
        "aa,bb,\"aa\",\"aa,bb\",\"aa\"\"\"aa\"\"\"\""};

    for (auto str : ss) {
        cout << s.parseCSV(str) << endl;
    }

    return 0;
}
