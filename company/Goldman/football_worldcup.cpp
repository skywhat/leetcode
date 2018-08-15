#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Complete the findMaxGoalsProbability function below.
string findMaxGoalsProbability(vector<int> teamGoals) {
    int n = teamGoals.size();
    if (n < 2) {
        return "0.00";
    }
    int total_rounds = n * (n - 1) / 2;
    sort(teamGoals.begin(), teamGoals.end());
    int max_score = teamGoals[n - 1];
    int second_max_score = teamGoals[n - 2];
    int cnt = 0;
    if (max_score > second_max_score) {
        for (int i = n - 2; i >= 0; i--) {
            if (teamGoals[i] == second_max_score) {
                cnt++;
            } else {
                break;
            }
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            if (teamGoals[i] == max_score) {
                cnt++;
            } else {
                break;
            }
        }
        cnt = cnt * (cnt - 1) / 2;
    }

    double prob = cnt / (double)total_rounds;
    string prob_str = to_string(prob);
    return prob_str.substr(0, 4);

    return to_string(prob);
}

int main() {
    vector<int> test1 = {3, 3, 3, 3};
    vector<int> test2 = {1, 2, 2, 3};
    vector<int> test3 = {1, 2, 3, 3};
    vector<int> test4 = {3, 3};
    vector<int> test5 = {1};
    vector<int> test6 = {0, 0, 0};
    vector<int> test7 = {5, 4, 3, 2, 1};
    vector<int> test8 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5};

    cout << findMaxGoalsProbability(test1) << endl;
    cout << findMaxGoalsProbability(test2) << endl;
    cout << findMaxGoalsProbability(test3) << endl;
    cout << findMaxGoalsProbability(test4) << endl;
    cout << findMaxGoalsProbability(test5) << endl;
    cout << findMaxGoalsProbability(test6) << endl;
    cout << findMaxGoalsProbability(test7) << endl;
    cout << findMaxGoalsProbability(test8) << endl;

    return 0;
}
