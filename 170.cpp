/*
 *lots of add and few find.
 */

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> m;
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto num: m){
            int num2 = value - num.first;
            if(num2== num.first && num.second>=2){
                return true;
            }
            else if(num2 != num.first && m.count(num2)){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */

int main(){
}
