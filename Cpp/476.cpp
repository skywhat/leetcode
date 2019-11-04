#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while(mask&num){
            mask<<=1;
        }
        return ~mask & ~num;
    }
};

int main(){
  Solution s;
  int test_num = 5;
  int expect_num = 2;

  cout<<(s.findComplement(test_num) == expect_num )<<endl;

  return 0;
}

/*
5 => 101
2 => 010
*/
