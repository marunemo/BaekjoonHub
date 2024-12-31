#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<int> cow;
vector<bool> visit;
vector<int> visit_count;

void DFS(int node) {
    visit[node] = true;
    for(int next: adj_list[node]) {
        if(!visit[next])
            DFS(next);
    }
}

int main() {
    int k, n, m;
    int a, b;
    int answer = 0;
    
    cin >> k >> n >> m;
    cow.resize(k);
    for(int i = 0; i < k; i++)
        cin >> cow[i];

    adj_list.resize(n + 1);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    visit.resize(n + 1);
    visit_count.resize(n + 1);
    for(int node: cow) {
        DFS(node);
        for(int i = 1; i <= n; i++) {
            visit_count[i] += visit[i];
            visit[i] = false;
        }
    }

    for(int i = 1; i <= n; i++)
        answer += visit_count[i] == k;

    cout << answer << endl;
    return 0;
}