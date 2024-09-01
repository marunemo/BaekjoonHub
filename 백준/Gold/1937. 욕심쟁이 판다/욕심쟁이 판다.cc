#include <iostream>
#include <algorithm>

using namespace std;
using Pos = pair<int, int>;
using Node = pair<int, Pos>;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int n;
int map[500][500];
Node node[250000];
int memo[500][500];

bool IsValid(int row, int col, int bamboo) {
    if(row < 0)
        return false;
    if(row >= n)
        return false;
    if(col < 0)
        return false;
    if(col >= n)
        return false;
    return map[row][col] > bamboo;
}

int DFS(int row, int col) {
    if(memo[row][col])
        return memo[row][col];

    int max_len = 1;
    for(int i = 0; i < 4; i++) {
        if(IsValid(row + dy[i], col + dx[i], map[row][col]))
            max_len = max(max_len, DFS(row + dy[i], col + dx[i]) + 1);
    }
    return memo[row][col] = max_len;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int max_len = 0;
    
    cin >> n;
    for(int row = 0, node_index = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            cin >> map[row][col];
            node[node_index++] = {map[row][col], {row, col}};
        }
    }
    sort(node, node + n * n, greater<Node>());

    for(int i = 0; i < n * n; i++) {
        auto [row, col] = node[i].second;
        max_len = max(max_len, DFS(row, col));
    }

    cout << max_len << endl;
    return 0;
}