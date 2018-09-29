// Implement an iterator to flatten a 2d vector.
//
// Example:
//
// Input: 2d vector =
// [
//   [1,2],
//   [3],
//   [4,5,6]
// ]
// Output: [1,2,3,4,5,6]
// Explanation: By calling next repeatedly until hasNext returns false,
//              the order of elements returned by next should be: [1,2,3,4,5,6].

class Vector2D {
public:
    vector<vector<int>>::iterator i, i_end;
    int j = 0;
    
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        i_end = vec2d.end();
    }

    int next() {
        hasNext();
        return (*i)[j++];
    }

    bool hasNext() {
        while (i != i_end && j == (*i).size()) {
            i++;
            j = 0;
        }

        return i != i_end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
