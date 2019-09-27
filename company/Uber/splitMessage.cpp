// Given a character limit and a message, split the message up into annotated
// chunks without cutting words as, for example when sending the SMS "Hi Swanky,
// your Uber is arriving now!" with char limit 25, you should get
// ["Hi Swanky,(1/3)", "your Uber is arriving(2/3)", "now!(3/3)"]

// https://www.careercup.com/question?id=5100595952222208
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitWord(string str, int limit) {
    vector<string> arr;
    vector<int> marks;
    vector<int> spaces;
    string size;
    int i, start, markIdx, spaceIdx;

    for (i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            spaces.push_back(i);
            if (i == 0)
                continue;
            switch (str[i - 1]) {
            case ',':
            case '.':
            case '?':
            case '!':
                marks.push_back(i);
            }
        }
    }
    spaces.push_back(i);
    marks.push_back(i);

    start = 0;
    markIdx = 0;
    spaceIdx = 0;
    while (markIdx < marks.size()) {
        if (marks[markIdx] - start <= limit) {
            markIdx++;
            continue;
        }

        if (markIdx > 0 && marks[markIdx - 1] > start
            && marks[markIdx - 1] - start <= limit) {
            arr.push_back(str.substr(start, marks[markIdx - 1] - start));
            start = marks[markIdx - 1] + 1;
        } else {
            while (spaceIdx < spaces.size()
                   && spaces[spaceIdx] <= start + limit)
                spaceIdx++;
            if (spaceIdx > 0 && spaces[spaceIdx] > start + limit)
                spaceIdx--;
            if (spaces[spaceIdx] > start && spaces[spaceIdx] <= start + limit) {
                arr.push_back(str.substr(start, spaces[spaceIdx] - start));
                start = spaces[spaceIdx] + 1;
            } else {
                arr.push_back(str.substr(start, limit));
                start += limit;
            }
        }
    }
    arr.push_back(str.substr(start, marks[markIdx - 1] - start));

    size = "/" + to_string((int)arr.size()) + ")";
    for (i = 0; i < arr.size(); i++) {
        arr[i] += "(" + to_string(i + 1) + size;
    }

    return arr;
}

vector<string> divide_str(const string& in, size_t chunk) {
    vector<string> out;
    if (in.empty()) {
        return out;
    }

    unsigned start = 0;
    while (start < in.length()) {
        unsigned end = min(start + chunk, in.length()) - 1;
        bool skip = false;
        if (end == in.length() - 1) {
            skip = true;
        } else if (end < in.length() && in[end + 1] == ' ') {
            skip = true;
        }
        unsigned next_start = end + 1;
        if (!skip) {
            while (start < end && in[end] != ' ') {
                --end;
            }
            next_start = end + 1;
            while (start < end && in[end] == ' ') {
                --end;
            }
        }
        out.push_back(in.substr(start, end - start + 1));
        start = next_start;
    }

    return out;
}

int main() {

    string test = "Hi Swanky, your Uber is arriving now!";
    int limit = 25;
    vector<string> res = divide_str(test, limit);
    for (auto s : res) {
        cout << s << "size=" << s.size() << endl;
    }

    test
        = "Extra spaces between words should be distributed as evenly as "
          "possible. If the number of spaces on a line do not divide evenly "
          "between words, the empty slots on the left will be assigned more "
          "spaces than the slots on the right.";

    res = divide_str(test, limit);
    for (auto s : res) {
        cout << s << "size=" << s.size() << endl;
    }
    return 0;
}
