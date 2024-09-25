#include <iostream>
#include <queue>
#define INF 50000001

using namespace std;
using Node = pair<int, int>;

vector<vector<Node>> adj_list;
vector<int> key;
priority_queue<Node, vector<Node>, greater<Node>> heap;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    int a, b, c;

    cin >> n >> m;
    key.resize(n + 1, INF);
    adj_list.resize(n + 1);
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    heap.push({0, 1});
    key[1] = 0;
    while(!heap.empty()) {
        auto [weight, pos] = heap.top();
        heap.pop();

        if(key[pos] < weight)
            continue;
        
        for(Node next: adj_list[pos]) {
            if(key[next.first] > next.second + weight) {
                key[next.first] = next.second + weight;
                heap.push({key[next.first], next.first});
            }
        }
    }
    cout << key[n] << endl;
    return 0;
}