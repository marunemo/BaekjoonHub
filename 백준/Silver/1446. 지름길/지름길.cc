#include <iostream>
#include <queue>
#define INF 100000000

using namespace std;
using Edge = pair<int, int>;

vector<vector<Edge>> adj_list;
vector<int> key;
priority_queue<Edge, vector<Edge>, greater<Edge>> heap;

int main() {
    int short_count, end_point;
    int src, dest, weight;

    cin >> short_count >> end_point;

    adj_list = vector<vector<Edge>>(end_point + 1, vector<Edge>());
    for(int i = 0; i < end_point; i++)
        adj_list[i].push_back({1, i + 1});
    for(int i = 0; i < short_count; i++) {
        cin >> src >> dest >> weight;
        if(dest <= end_point)
            adj_list[src].push_back({weight, dest});
    }

    key = vector<int>(end_point + 1, INF);
    key[0] = 0;
    heap.push({0, 0});

    while(!heap.empty()) {
        Edge current = heap.top();
        heap.pop();

        if(current.first > key[current.second])
            continue;
        
        for(Edge next: adj_list[current.second]) {
            if(key[next.second] > current.first + next.first) {
                key[next.second] = current.first + next.first;
                heap.push({current.first + next.first, next.second});
            }
        }
    }

    cout << key[end_point] << endl;
    return 0;
}