/*

 Given a list accounts, each element accounts[i] is a list of strings, where the
 first element accounts[i][0] is a name, and the rest of the elements are emails
 representing emails of the account.

 Now, we would like to merge these accounts. Two accounts definitely belong to
 the same person if there is some email that is common to both accounts. Note
 that even if two accounts have the same name, they may belong to different
 people as people could have the same name. A person can have any number of
 accounts initially, but all of their accounts definitely have the same name.

 After merging the accounts, return the accounts in the following format: the
 first element of each account is the name, and the rest of the elements are
 emails in sorted order. The accounts themselves can be returned in any order.

 Example 1:
 Input:
 accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John",
 "johnnybravo@mail.com"], ["John", "johnsmith@mail.com",
 "john_newyork@mail.com"], ["Mary", "mary@mail.com"]] Output: [["John",
 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John",
 "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]] Explanation: The first and
 third John's are the same person as they have the common email
 "johnsmith@mail.com". The second John and Mary are different people as none of
 their email addresses are used by other accounts. We could return these lists
 in any order, for example the answer [['Mary', 'mary@mail.com'], ['John',
 'johnnybravo@mail.com'],
 ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
 would still be accepted. Note:

 The length of accounts will be in the range [1, 1000].
 The length of accounts[i] will be in the range [1, 10].
 The length of accounts[i][j] will be in the range [1, 30].

 */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// union find

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> owner;
        map<string, string> parent;
        map<string, set<string>> united;
        vector<vector<string>> res;

        for (auto&& ac : accounts) {
            for (int i = 1; i < ac.size(); ++i) {
                owner[ac[i]] = ac[0];
                parent[ac[i]] = ac[i];
            }
        }
        // union the email to the only parent
        for (auto&& ac : accounts) {
            string p = find(ac[1], parent);
            for (int i = 2; i < ac.size(); ++i) {
                parent[find(ac[i], parent)] = p;
            }
        }

        // find parent's all the children
        for (auto&& item : parent) {
            united[find(item.second, parent)].insert(item.first);
        }
        for (auto&& u : united) {
            vector<string> tmp(u.second.begin(), u.second.end());
            tmp.insert(tmp.begin(), owner[u.first]);
            res.push_back(tmp);
        }
        return res;
    }
    
    string find(string x, map<string, string>& m) {
        while (m[x] != x) {
            m[x] = m[m[x]]; // path compression
            x = m[x];
        }
        return x;
    }
};

int main() {}
