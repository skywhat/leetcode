#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<string, int> m;
    unordered_map<string, string> callbackm;

    Solution() { this->m[""] = 0; }

    bool create(string key, int value) {
        if (m.count(key)) {
            return false;
        }

        size_t pos = key.rfind('/');
        if (pos == string::npos) {
            return false;
        }

        string prefix = key.substr(0, pos);
        if (!m.count(prefix)) {
            return false;
        }

        m[key] = value;
        return true;
    }

    bool set(string key, int value) {
        if (!m.count(key)) {
            return false;
        }

        m[key] = value;
        while (!key.empty()) {
            if (callbackm.count(key)) {
                cout << callbackm[key] << endl;
            }
            size_t pos = key.rfind('/');
            if (pos == string::npos) {
                break;
            }
            key = key.substr(0, pos);
        }

        return true;
    }

    int get(string key) {
        if (!m.count(key)) {
            return -1;
        }

        return m[key];
    }

    void watch(string path, string alert) {
        callbackm[path] = alert;
    }
};

int main() {
    Solution s;

    s.create("/a", 1);
    cout << s.get("/a") << endl;
    s.create("/a/b", 2);
    cout << s.get("/a/b") << endl;
    s.create("/c/d", 3);
    cout << s.get("/c") << endl;
    s.set("/a/b", 4);
    cout << s.get("/a/b") << endl;
    s.watch("/a", "/a call back triggerred");
    s.watch("/a/b", "/a/b call back triggerred");
    s.set("/d", 5);
    s.create("/a/b/c", 10);
    s.set("/a/b/c", 11);
    cout << s.get("/a/b/c") << endl;
}
