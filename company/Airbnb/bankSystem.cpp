/**
 * 设计一个银行帐户系统，实现：
 * 存钱（帐户id，存钱数目，日期）
 * 取钱（帐户id，存钱数目，日期）
 * 查账（帐户id，起始日期，结束日期）：
 * 只需要返回两个数值，一个是起始日期的balance，一个是结束日期的balance。
 * 描述就是这么多，剩下的自己发挥。钱的类型用integer，日期什么的自定义，我直接拿了integer
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

class Bank {
public:
    map<int, int> balance;          // id => money
    map<int, map<ll, int>> history; // id => (timestamp => money)

    void deposite(int id, int amount, ll timestamp) {
        balance[id] += amount;
        history[id][timestamp] = balance[id];
    }

    bool withdraw(int id, int amount, ll timestamp) {
        if (!balance.count(id)) {
            return false;
        }
        balance[id] -= amount;
        history[id][timestamp] = balance[id];

        return true;
    }

    vector<int> check(int id, ll start_time, ll end_time) {
        if (!balance.count(id)) {
            return {};
        }

        vector<int> res(2);
        if (history[id].count(start_time)) {
            res[0] = history[id][start_time];
        } else {
            auto it = history[id].upper_bound(start_time);
            if (it == history[id].begin()) {
                res[0] = 0;
            } else {
                res[0] = (--it)->second;
            }
        }

        if (history[id].count(end_time)) {
            res[1] = history[id][end_time];
        } else {
            auto it = history[id].upper_bound(end_time);
            if (it == history[id].begin()) {
                res[1] = 0;
            } else {
                res[1] = (--it)->second;
            }
        }

        return res;
    }
};

int main() {
    Bank b;
    cout << b.withdraw(0, 100, 0) << endl; // false
    b.deposite(0, 100, 1);
    b.deposite(1, 250, 2);
    b.withdraw(0, 30, 3);

    vector<int> bill = b.check(0, 0, 2);
    cout << "start: " << bill[0] << " end: " << bill[1] << endl; // [0, 100]
    b.deposite(1, 5, 7);

    bill = b.check(1, 0, 9);
    cout << "start: " << bill[0] << " end: " << bill[1] << endl; // [0, 255]
    bill = b.check(1, 3, 9);
    cout << "start: " << bill[0] << " end: " << bill[1] << endl; // [250, 255]
    bill = b.check(1, 10, 12);
    cout << "start: " << bill[0] << " end: " << bill[1] << endl; // [255, 255]

    return 0;
}
