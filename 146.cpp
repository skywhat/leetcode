// Design and implement a data structure for Least Recently Used (LRU) cache. It
// should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key
// exists in the cache, otherwise return -1. put(key, value) - Set or insert the
// value if the key is not already present. When the cache reached its capacity,
// it should invalidate the least recently used item before inserting a new
// item.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LRUCache cache = new LRUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);    // returns 1
// cache.put(3, 3); // evicts key 2
// cache.get(2);    // returns -1 (not found)
// cache.put(4, 4); // evicts key 1
// cache.get(1);    // returns -1 (not found)
// cache.get(3);    // returns 3
// cache.get(4);    // returns 4

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class LRUCache {
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> seek_ptr;
    size_t _capacity;
    LRUCache(int capacity) { _capacity = capacity; }

    int get(int key) {
        if (!seek_ptr.count(key)) {
            return -1;
        }
        cache.splice(cache.begin(), cache, seek_ptr[key]);
        seek_ptr[key] = cache.begin();
        return cache.front().second;
    }

    void put(int key, int value) {
        if (seek_ptr.count(key)) {
            cache.splice(cache.begin(), cache, seek_ptr[key]);
            seek_ptr[key] = cache.begin();
            cache.front().second = value;
            return;
        }

        if (_capacity == cache.size()) {
            int del_key = cache.back().first;
            cache.pop_back();
            seek_ptr.erase(del_key);
        }
        cache.push_front(make_pair(key, value));
        seek_ptr[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {}
