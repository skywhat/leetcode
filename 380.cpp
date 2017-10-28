#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> help;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val)!=m.end())
            return false;
        help.push_back(val);
        m[val]=help.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val)==m.end())
            return false;
        int pos=m[val];
        help[pos]=help.back();
        help.pop_back();
        m[help[pos]]=pos;
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return help[rand()%help.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(){

}
