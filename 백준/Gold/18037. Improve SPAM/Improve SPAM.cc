#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int address_count, list_count;
bool send[2001] = {false};
vector<vector<int>> adj_list;
bool visit[2001] = {false};
int memo[2001] = {0};
int before_count = 0, after_count = 0;

int DFS(int node) {
    if(visit[node])
        return memo[node];

    visit[node] = true;
    for(int next: adj_list[node]) {
        if(next <= list_count)
            memo[node] = (memo[node] + DFS(next)) % MOD;
        else {
            if(!send[next]) {
                send[next] = true;
                after_count = (after_count + 1) % MOD;
            }
            memo[node] = (memo[node] + 1) % MOD;
        }
    }
    return memo[node];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int node_count;

    cin >> address_count >> list_count;
    adj_list.resize(list_count + 1);

    for(int i = 1; i <= list_count; i++) {
        cin >> node_count;
        adj_list[i].resize(node_count);
        for(int j = 0; j < node_count; j++)
            cin >> adj_list[i][j];
    }

    before_count = DFS(1);

    cout << before_count << ' ' << after_count << endl;
    return 0;
}