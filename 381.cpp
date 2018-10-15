// Design a data structure that supports all following operations in average
// O(1) time.
//
// Note: Duplicate elements are allowed.
// insert(val): Inserts an item val to the collection.
// remove(val): Removes an item val from the collection if present.
// getRandom: Returns a random element from current collection of elements. The
// probability of each element being returned is linearly related to the number
// of same value the collection contains. Example:
//
// // Init an empty collection.
// RandomizedCollection collection = new RandomizedCollection();
//
// // Inserts 1 to the collection. Returns true as the collection did not
// contain 1. collection.insert(1);
//
// // Inserts another 1 to the collection. Returns false as the collection
// contained 1. Collection now contains [1,1]. collection.insert(1);
//
// // Inserts 2 to the collection, returns true. Collection now contains
// [1,1,2]. collection.insert(2);
//
// // getRandom should return 1 with the probability 2/3, and returns 2 with the
// probability 1/3. collection.getRandom();
//
// // Removes 1 from the collection, returns true. Collection now contains
// [1,2]. collection.remove(1);
//
// // getRandom should return 1 and 2 both equally likely.
// collection.getRandom();

class RandomizedCollection {
public:
    vector<pair<int, int>> vp;
    unordered_map<int, vector<int>> m;
    /** Initialize your data structure here. */
    RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did
     * not already contain the specified element. */
    bool insert(int val) {
        bool res = m.find(val) == m.end();

        m[val].push_back(vp.size());
        vp.push_back({val, m[val].size() - 1});

        return res;
    }

    /** Removes a value from the collection. Returns true if the collection
     * contained the specified element. */
    bool remove(int val) {
        bool res = m.find(val) == m.end();
        if (res) {
            return false;
        }

        pair<int, int> last = vp.back();
        vp[m[val].back()] = last;
        m[last.first][last.second] = m[val].back();
        vp.pop_back();
        m[val].pop_back();
        if (m[val].empty()) {
            m.erase(val);
        }

        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int ind = rand() % vp.size();
        return vp[ind].first;
    }
};

/*
0       1       2      3     4      5
<1, 0> <2, 0> <1, 1> <3, 0> <1, 2> <2, 1>
m[1] = {0, 2, 4}
m[2] = {1, 5}
m[3] = {3}
*/

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
