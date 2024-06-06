#include <iostream>
#include <vector>

using namespace std;

int vertice_count[100001];
bool visit[100001] = {false};
vector<vector<int>> adj_list;

void DFS(int node) {
    visit[node] = true;
    vertice_count[node] = 1;

    for(int vertice: adj_list[node]) {
        if(!visit[vertice]) {
            DFS(vertice);
            vertice_count[node] += vertice_count[vertice];
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, r, q;
    int s, e;

    cin >> n >> r >> q;
    adj_list = vector<vector<int>>(n + 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> s >> e;
        adj_list[s].push_back(e);
        adj_list[e].push_back(s);
    }

    DFS(r);

    while(q--) {
        cin >> r;
        cout << vertice_count[r] << '\n';
    }
    return 0;
}