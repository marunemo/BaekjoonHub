#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

queue<int> q;
vector<vector<int>> adj_list;
vector<unordered_map<int, bool>> contain;
unordered_map<int, bool> visit[2];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, x, y, s, e;
    int size, node;
    bool none = true;

    cin >> n >> m >> x >> y;
    adj_list.resize(n + 1);
    contain.resize(n + 1);
    for(int i = 0; i < m; i++) {
        cin >> s >> e;
        if(!contain[s][e]) {
            adj_list[s].push_back(e);
            contain[s][e] = true;
        }
        if(!contain[e][s]) {
            adj_list[e].push_back(s);
            contain[e][s] = true;
        }
    }

    q.push(x);
    for(int i = 1; i <= y; i++) {
        size = q.size();
        for(int j = 0; j < size; j++) {
            node = q.front();
            q.pop();

            for(int next: adj_list[node]) {
                if(!visit[i % 2][next]) {
                    q.push(next);
                    visit[i % 2][next] = true;
                }
            }
        }
    }

    for(node = 1; node <= n; node++) {
        if(visit[y % 2][node]) {
            none = false;
            cout << node << ' ';
        }
    }

    if(none)
        cout << -1;
    cout << endl;
    return 0;
}