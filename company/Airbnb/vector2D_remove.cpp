#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Vector2D {
public:
    vector<vector<int>>::iterator i, i_end, i_begin;
    int j = 0;
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        i_end = vec2d.end();
        i_begin = vec2d.begin();
    }

    int next() {
        if (hasNext()) {
            return (*i)[j++];
        }

        cout << "it's empty!" << endl;
        return -1;
    }

    bool hasNext() {
        while (i != i_end && j == (*i).size()) {
            i++;
            j = 0;
        }

        return i != i_end;
    }

    void remove() {
        if (j == 0) {
            auto prev_i = prev(i);
            while (prev_i != i_begin && (*prev_i).empty()) {
                prev_i = prev(prev_i);
            }
            if (!(*prev_i).empty()) {
                (*prev_i).pop_back();
            } else {
                cout << "you need to call next first!" << endl;
                return;
            }
        } else {
            j--;
            (*i).erase((*i).begin() + j);
        }

        cout << "remove!" << endl;
    }
};

void print(vector<vector<int>>& v) {
    cout << "print" << endl;
    for (auto row : v) {
        for (auto i : row) {
            cout << i << ", ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> vec_2d = {{1, 2, 3, 4, 5}, {}, {6, 7, 8}, {9}};

    Vector2D v2(vec_2d);
    int i = 6;
    while (i--) {
        if (v2.hasNext()) {
            cout << v2.next() << endl;
        }
    }
    print(vec_2d);

    v2.remove();
    v2.remove();
    v2.remove();
    v2.remove();
    v2.remove();
    v2.remove();
    v2.remove();

    print(vec_2d);

    i = 3;
    while (i--) {
        if (v2.hasNext()) {
            cout << v2.next() << endl;
        }
    }
    print(vec_2d);
    v2.remove();
    v2.remove();
    v2.remove();
    v2.remove();
    print(vec_2d);

    if (v2.hasNext()) {
        cout << v2.next() << endl;
    }
    return 0;
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
