// Given a list of airline tickets represented by pairs of departure and arrival
// airports [from, to], reconstruct the itinerary in order. All of the tickets
// belong to a man who departs from JFK. Thus, the itinerary must begin with
// JFK.
//
// Note:
//
// If there are multiple valid itineraries, you should return the itinerary that
// has the smallest lexical order when read as a single string. For example, the
// itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"]. All
// airports are represented by three capital letters (IATA code). You may assume
// all tickets form at least one valid itinerary. Example 1:
//
// Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
// Example 2:
//
// Input:
// [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is
// ["JFK","SFO","ATL","JFK","ATL","SFO"].
//              But it is larger in lexical order.

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> m;
        for (auto t : tickets) {
            m[t.first].insert(t.second);
        }

        vector<string> res;
        stack<string> path;
        path.push("JFK");
        while (!path.empty()) {
            string start = path.top();
            if (m[start].empty()) {
                res.push_back(start);
                path.pop();
            } else {
                path.push(*m[start].begin());
                m[start].erase(m[start].begin());
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
