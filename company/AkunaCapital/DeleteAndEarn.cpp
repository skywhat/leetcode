/*
 Given an array of n integers named elements, we can perform several steps on the array. In each step, we choose an elementsi from the array and delete it to earn elements i points; However, deleting elements i also deletes any integers equal to elements i + 1 and elements i - 1 from elements. For exampls, if elements = [1,2,3,4], deleting 2 results in elements becoming [4] and earns us 2 points.
 
 Compute the maxPoints function that has one parameter; an array of n integers named elements. The function must return a long integer denoting the maximum number of points we can earn by performing steps.
 
 Constraints
 
 1<= n <= 10 (to the power 5)
 
 1 <= elements i <= 10 (to the power 5)
 
 Sample Input : [3,4,2]
 Output : 6
 
 Explanation:
 Given elements = [3,4,2], we maximize our score by performing the following steps:
 
 Delete 4 to earn 4 points, which also deletes 4 - 1 = 3 and elements becomes [2].
 Delete 2 to earn 2 points and elements become []
 There are no more elements to delete, so we can't perform any more steps. The function returns the total number of points which is 4 + 2 = 6.
 */

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
	long maxPoints(vector<int> elements){
		int maxValue=0;
		unordered_map<int,int> m;
		for(auto& e:elements){
			maxValue=max(e,maxValue);	
			m[e]++;
		}
		vector<int> dp(maxValue+1,0);
		dp[1]=m[1];
		for(int i=2;i<=maxValue;++i){
			/*
			 * if you pick the element i, you could also add element i-2,
			 *  m[i]*i is the value you could earn due to i
			 *  if you don't pick the element i, dp[i] would still be the previous element i-1
			 */
			dp[i]=max(dp[i-1],dp[i-2]+m[i]*i);
		}
		return dp[maxValue];
	}
};

int main(){
	vector<int> elements={1,2,1,3,2,3};//expected 8
	vector<int> elements2={3,3,4,2};//expected 6
	Solution s;
	cout<<s.maxPoints(elements2)<<endl;

	return 0;

}
