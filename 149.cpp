// Given n points on a 2D plane, find the maximum number of points that lie on
// the same straight line.
//
// Example 1:
//
// Input: [[1,1],[2,2],[3,3]]
// Output: 3
// Explanation:
// ^
// |
// |        o
// |     o
// |  o
// +------------->
// 0  1  2  3  4
// Example 2:
//
// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
// Explanation:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) {
            return points.size();
        }
        int max_points = 0;
        int res = 0;

        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, unordered_map<int, int>> m;
            int same_points = 1;
            int local_max = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                int x = points[j].x - points[i].x;
                int y = points[j].y - points[i].y;
                if (x == 0 && y == 0) {
                    same_points++;
                    continue;
                }

                int gcd = GCD(x, y);
                if (gcd != 0) {
                    x /= gcd;
                    y /= gcd;
                }

                m[x][y]++;
                local_max = max(local_max, m[x][y]);
            }
            res = max(res, local_max + same_points);
        }

        return res;
    }

    int GCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return GCD(b, a % b);
    }
};
