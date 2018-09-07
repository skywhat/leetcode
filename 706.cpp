// Design a HashMap without using any built-in hash table libraries.
//
// To be specific, your design should include these functions:
//
// put(key, value) : Insert a (key, value) pair into the HashMap. If the value
// already exists in the HashMap, update the value. get(key): Returns the value
// to which the specified key is mapped, or -1 if this map contains no mapping
// for the key. remove(key) : Remove the mapping for the value key if this map
// contains the mapping for the key.
//
// Example:
//
// MyHashMap hashMap = new MyHashMap();
// hashMap.put(1, 1);
// hashMap.put(2, 2);
// hashMap.get(1);            // returns 1
// hashMap.get(3);            // returns -1 (not found)
// hashMap.put(2, 1);          // update the existing value
// hashMap.get(2);            // returns 1
// hashMap.remove(2);          // remove the mapping for 2
// hashMap.get(2);            // returns -1 (not found)
//
// Note:
//
// All keys and values will be in the range of [0, 1000000].
// The number of operations will be in the range of [1, 10000].
// Please do not use the built-in HashMap library.

struct HashNode {
    int key;
    int value;
    HashNode* next;
    HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    const int bucket_size = 1000;
    MyHashMap() {}

    /** value will always be non-negative. */
    void put(int key, int value) {
        HashNode* prev = findPrev(key);
        if (prev->next) {
            prev->next->value = value;
            return;
        }

        int index = getIndex(key);
        HashNode* next = buckets[index].next;
        HashNode* node = new HashNode(key, value);
        buckets[index].next = node;
        node->next = next;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this
     * map contains no mapping for the key */
    int get(int key) {
        HashNode* prev = findPrev(key);
        if (prev->next == nullptr) {
            return -1;
        }

        return prev->next->value;
    }

    /** Removes the mapping of the specified value key if this map contains a
     * mapping for the key */
    void remove(int key) {
        HashNode* prev = findPrev(key);
        if (prev->next) {
            HashNode* temp = prev->next;
            prev->next = temp->next;
            temp->next = nullptr;
            delete temp;
        }
    }

private:
    vector<HashNode> buckets = vector<HashNode>(bucket_size, HashNode(-1, -1));

    int getIndex(int key) { return key % bucket_size; }

    HashNode* findPrev(int key) {
        int index = getIndex(key);
        HashNode* cur = &buckets[index];
        HashNode* prev = nullptr;
        while (cur && cur->key != key) {
            prev = cur;
            cur = cur->next;
        }

        return prev;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
