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
        for(auto it=m.begin();it!=m.end();++it){
            int num1=it->first;
            int num2=value-num1;
            if(num1==num2&&it->second>=2)
                return true;
            else if(num1!=num2&&m.find(num2)!=m.end())
                return true;
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
