#include<iostream>
#include<string>

using namespace std;

class Solution {
private:
  int x = 0, y = 0;

public:
  bool judgeCircle(string moves) {
    for (int i = 0; i < moves.size(); ++i) {
      switch (moves[i]) {
      case 'L':
        x--;
        break;
      case 'R':
        x++;
        break;
      case 'U':
        y++;
        break;
      case 'D':
        y--;
        break;
      default:
        break;
      }
    }

    return x == 0 && y == 0;
  }
};

int main(){
	string testcase="UD";
	string testcase1="DURDLDRRLL";
	Solution s;
	cout<<s.judgeCircle(testcase1)<<endl;

	return 0;
}


