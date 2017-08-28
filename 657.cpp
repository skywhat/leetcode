#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
	struct pos{
		int x;
		int y;
		pos():x(0),y(0){}
	};
	bool judgeCircle(string moves){
		pos p;
		for(int i=0;i<moves.size();++i){
			add(p,moves[i]);
		}
		if(p.x==0&&p.y==0)
			return true;
		else
			return false;

	}
	void add(pos &p,char c){
		switch(c){
		case 'U':p.y++;
				 break;
		case 'D':p.y--;
				 break;
		case 'L':p.x--;
				 break;
		case 'R':p.x++;
				 break;
		default:break;
		}
	}
};

int main(){
	string testcase="UD";
	string testcase1="DURDLDRRLL";
	Solution s;
	cout<<s.judgeCircle(testcase1)<<endl;

	return 0;
}


