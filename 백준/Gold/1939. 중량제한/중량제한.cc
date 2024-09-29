#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001

using namespace std;
using pii = pair<int, int>;

struct Bridge {
    int src, dest, weight;
};

bool Compare(Bridge a, Bridge b) {
    return a.weight > b.weight;
}

int UnionFind(vector<int> &parent, int node) {
    if(parent[node] == node)
        return node;
    return parent[node] = UnionFind(parent, parent[node]);
}

int DFS(vector<vector<pii>> const &adj_list, vector<bool> &visit, int node, int dest, int weight) {
    if(node == dest)
        return weight;

    if(visit[node])
        return INF;
    visit[node] = true;
    
    int min_weight = INF;
    for(pii next: adj_list[node])
        min_weight = min(min_weight, DFS(adj_list, visit, next.first, dest, min(weight, next.second)));
    return min_weight;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int node_count, bridge_count;
    vector<Bridge> bridge;
    vector<int> parent;
    vector<vector<pii>> adj_list;
    vector<bool> visit;
    int src, dest;

    cin >> node_count >> bridge_count;
    bridge.resize(bridge_count);
    for(int i = 0; i < bridge_count; i++)
        cin >> bridge[i].src >> bridge[i].dest >> bridge[i].weight;
    sort(bridge.begin(), bridge.end(), Compare);

    parent.resize(node_count + 1);
    for(int i = 1; i <= node_count; i++)
        parent[i] = i;
    
    // adj_list로 Maximum Spanning Tree 생성
    adj_list.resize(node_count + 1);
    for(Bridge edge: bridge) {
        auto [src, dest, weight] = edge;

        if(UnionFind(parent, src) == UnionFind(parent, dest))
            continue;
        
        if(parent[src] < parent[dest])
            parent[parent[dest]] = parent[src];
        else
            parent[parent[src]] = parent[dest];

        adj_list[src].push_back({dest, weight});
        adj_list[dest].push_back({src, weight});
    }

    cin >> src >> dest;
    visit.resize(node_count + 1, false);

    cout << DFS(adj_list, visit, src, dest, INF) << endl;
    return 0;
}