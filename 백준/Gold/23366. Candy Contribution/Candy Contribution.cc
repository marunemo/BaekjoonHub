#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

vector<pii> adj_list[100001];
int key[100001];
priority_queue<pii, vector<pii>, less<pii>> pq;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int country, border;
    int start, end, init;
    int node1, node2, tax;

    cin >> country >> border;
    cin >> start >> end >> init;

    for(int i = 0; i < border; i++) {
        cin >> node1 >> node2 >> tax;
        
        adj_list[node1].push_back({node2, tax});
        adj_list[node2].push_back({node1, tax});
    }

    key[start] = init;
    pq.push({init, start});

    while(!pq.empty()) {
        int candy = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(pii next: adj_list[node]) {
            long long new_candy = (long long)candy * (100 - next.second) / 100;
            if(key[next.first] >= new_candy)
                continue;
            
            key[next.first] = new_candy;
            pq.push({new_candy, next.first});
        }
    }

    cout << key[end] << endl;
    return 0;
}