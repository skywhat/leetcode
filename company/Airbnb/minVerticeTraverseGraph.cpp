#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef pair<int, int> pr;
typedef unordered_map<int, unordered_set<int>> connectInfo;
void fromDFS(int node,
             connectInfo from,
             vector<int>& order,
             unordered_set<int>& visited) {
    if (!visited.count(node)) {
        visited.insert(node);
        for (auto n : from[node])
            fromDFS(n, from, order, visited);
        order.insert(order.begin(), node);
    }
}

void toDFS(int node,
           int root,
           connectInfo to,
           unordered_map<int, int>& components) {
    if (!components.count(node)) {
        components[node] = root;
        for (auto n : to[node]) {
            toDFS(n, root, to, components);
        }
    }
}

unordered_map<int, int> kosaraju(connectInfo from,
                                 connectInfo to,
                                 const unordered_set<int>& nodes) {
    unordered_set<int> visited;
    unordered_map<int, int> components;
    vector<int> order;
    for (auto node : nodes)
        fromDFS(node, from, order, visited);
    for (auto node : order)
        toDFS(node, node, to, components);
    return components;
}

vector<int> least_nodes(const vector<pr>& edges) {
    connectInfo from, to;
    unordered_set<int> nodes;
    vector<int> ans;
    for (auto edge : edges) {
        from[edge.first].insert(edge.second);
        to[edge.second].insert(edge.first);
        nodes.insert(edge.first);
        nodes.insert(edge.second);
    }

    unordered_map<int, int> components = kosaraju(from, to, nodes);
    unordered_set<int> fromComponents, toComponents;
    for (auto edge : edges) {
        fromComponents.insert(components[edge.first]);
        if (components[edge.first] != components[edge.second]) {
            toComponents.insert(components[edge.second]);
        }
    }

    for (auto node : fromComponents)
        if (!toComponents.count(node))
            ans.push_back(node);
    return ans;
}

int main() {
    vector<pr> edges = {{0, 0}, {1, 2}, {2, 0}, {2, 3}, {3, 1}};
    vector<int> ans = least_nodes(edges);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}
