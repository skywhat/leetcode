#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        
        int one_step_behind = 1;
        int two_steps_behind = 1;
        int cur;
        for(int i=2;i<=n;++i){
            cur = one_step_behind+two_steps_behind;
            two_steps_behind = one_step_behind;
            one_step_behind = cur;
        }
        
        return cur;
    }
};

int main() {
	int n = 10;
	Solution s;
	cout << s.climbStairs(n) << endl;

	return 0;
}
