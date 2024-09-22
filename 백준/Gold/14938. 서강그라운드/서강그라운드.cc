#include <iostream>
#include <queue>
#define INF 16

using namespace std;
using Node = pair<int, int>;

int node_count, range, edge_count;
vector<int> item;
vector<vector<Node>> adj_list;
priority_queue<Node, vector<Node>, greater<Node>> heap;
vector<int> min_dist;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int src, dest, len;
    int count, max_count = 0;

    cin >> node_count >> range >> edge_count;

    item.resize(node_count + 1);
    adj_list.resize(node_count + 1);
    
    for(int i = 1; i <= node_count; i++)
        cin >> item[i];
    for(int i = 0; i < edge_count; i++) {
        cin >> src >> dest >> len;
        adj_list[src].push_back({len, dest});
        adj_list[dest].push_back({len, src});
    }

    for(int start = 1; start <= node_count; start++) {
        min_dist = vector<int>(node_count + 1, INF);

        heap.push({0, start});
        min_dist[start] = 0;
        count = 0;

        while(!heap.empty()) {
            auto [dist, pos] = heap.top();
            heap.pop();

            if(dist > min_dist[pos])
                continue;
            count += item[pos];

            for(Node next: adj_list[pos]) {
                if(next.first + dist <= range && min_dist[next.second] > next.first + dist) {
                    min_dist[next.second] = next.first + dist;
                    heap.push({next.first + dist, next.second});
                }
            }
        }

        max_count = max(count, max_count);
    }
    cout << max_count << endl;
    return 0;
}