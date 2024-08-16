#include <iostream>
#include <queue>

using namespace std;
using pli = pair<long long, int>;

vector<vector<pli>> adj_list;
vector<int> key;
priority_queue<pli, vector<pli>, less<pli>> pq;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int country, border;
    int start, end, init;
    int node1, node2, tax;

    cin >> country >> border;
    cin >> start >> end >> init;

    adj_list = vector<vector<pli>>(country + 1);
    for(int i = 0; i < border; i++) {
        cin >> node1 >> node2 >> tax;
        
        adj_list[node1].push_back({node2, tax});
        adj_list[node2].push_back({node1, tax});
    }

    key = vector<int>(country + 1, 0);
    key[start] = init;
    pq.push({init, start});

    while(!pq.empty()) {
        long long candy = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(pli next: adj_list[node]) {
            long long new_candy = candy * (100 - next.second) / 100;
            if(key[next.first] >= new_candy)
                continue;
            
            key[next.first] = new_candy;
            pq.push({new_candy, next.first});
        }
    }

    cout << key[end] << endl;
    return 0;
}