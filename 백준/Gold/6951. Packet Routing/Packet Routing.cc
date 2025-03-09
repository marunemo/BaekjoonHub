#include <iostream>
#include <queue>

using namespace std;
using Edge = pair<int, int>;

vector<vector<Edge>> adj_list;

int Dijkstra(int node_count, int dest, int src) {
    vector<int> key = vector<int>(node_count + 1, 1e8);
    priority_queue<Edge> pq;

    key[dest] = 0;
    pq.push({dest, 0});

    while(!pq.empty()) {
        auto [node, cost] = pq.top();
        pq.pop();

        if(node == src) {
            return cost;
        }

        for(Edge edge: adj_list[node]) {
            if(key[edge.first] > cost + edge.second) {
                key[edge.first] = cost + edge.second;
                pq.push({edge.first, key[edge.first]});
            }
        }
    }

    return 1e8;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, w, p;
    int src, dest, cost;

    cin >> n >> w >> p;

    adj_list.resize(n + 1);
    for(int i = 0; i < w; i++) {
        cin >> dest >> src >> cost;

        adj_list[dest].push_back({src, cost});
        adj_list[src].push_back({dest, cost});
    }

    for(int i = 0; i < p; i++) {
        cin >> dest >> src;

        cout << Dijkstra(n, dest, src) << '\n';
    }
    return 0;
}