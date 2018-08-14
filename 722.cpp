#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        stringstream ss;
        const char* delim = "\n";
        copy(source.begin(), source.end(), ostream_iterator<string>(ss, delim));
        string s = ss.str();
        // cout << s;
        regex e("//.*|/\\*(.|\n)*?\\*/");
        string ns = regex_replace(s, e, "");
        ss.str(ns);
        vector<string> res;

        while (ss.good()) {
            string token;
            getline(ss, token, '\n');
            if (!token.empty()) {
                res.push_back(token);
            }
        }

        // copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));
        return res;
    }
};

class Solution2 {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool is_block = false;
        string line;

        for (int i = 0; i < source.size(); ++i) {
            for (int j = 0; j < source[i].size(); ++j) {
                if (!is_block) {
                    if (!line.empty() && line.back() == '/' && source[i][j] == '/') {
                        line.pop_back();
                        break;
                    } else if (!line.empty() && line.back() == '/' && source[i][j] == '*') {
                        line.pop_back();
                        is_block = true;
                    } else {
                        line.push_back(source[i][j]);
                    }
                } else {
                    if (source[i][j] == '*' && j + 1 < source[i].size()
                        && source[i][j + 1] == '/') {
                        is_block = false;
                        j++;
                    }
                }
            }

            if (!line.empty() && !is_block) {
                res.push_back(line);
                line = "";
            }
        }

        return res;
    }
};

int main() {
    vector<string> test = {"/*Test program */",
                           "int main()",
                           "{ ",
                           "  // variable declaration ",
                           "int a, b, c;",
                           "/* This is a test",
                           "   multiline  ",
                           "   comment for ",
                           "   testing */",
                           "a = b + c;",
                           "}"};

    Solution2 s;
    vector<string> res = s.removeComments(test);
    copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
