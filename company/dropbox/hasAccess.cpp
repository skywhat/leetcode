// /A
// |___ /B .
//     |___ /C <-- access
//     |___ /D
// |___ /E <-- access
//     |___ /F.
//         |___ /G

// folders = [
//   ('A', None),
//   ('B', 'A'),
//   ('C', 'B'),
//   ('D', 'B'),
//   ('E', 'A'),
//   ('F', 'E'),
//   ('G', 'F'),
// ]

// access = set(['C', 'E'])

// has_access(String folder_name) -> boolean.
// has_access("B") -> false.
// has_access("C") -> true
// has_access("F") -> true
// has_access("G") -> true

// http://www.1point3acres.com/bbs/thread-341713-1-1.html

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    map<string, string> file_tree; // key: child value: parent
    set<string> access;

    void setAccess(vector<vector<string>> folders, set<string> access) {
        this->access = access;
        for (auto f : folders) {
            file_tree[f[0]] = f[1];
        }
    }

    bool hasAccess(string folder_name) {
        if (folder_name.empty()) {
            return false;
        }

        if (access.count(folder_name)) {
            return true;
        }

        return hasAccess(file_tree[folder_name]);
    }
};

int main() {
    vector<vector<string>> folders = {
        {"A", ""},
        {"B", "A"},
        {"C", "B"},
        {"D", "B"},
        {"E", "A"},
        {"F", "E"},
        {"G", "F"},
    };

    set<string> access = {"C", "E"};

    Solution s;
    s.setAccess(folders, access);

    cout << s.hasAccess("B") << endl;
    cout << s.hasAccess("C") << endl;
    cout << s.hasAccess("F") << endl;
    cout << s.hasAccess("G") << endl;

    return 0;
}
