#include <iostream>
#include <queue>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int n, m;
int map[1000][1000];
int dist[1000][1000];

bool InRange(int row, int col) {
    if(row < 0)
        return false;
    if(row >= n)
        return false;
    if(col < 0)
        return false;
    if(col >= m)
        return false;
    return true;
}

void BFS(int row, int col) {
    queue<pair<int, int>> q;
    q.push({row, col});
    dist[row][col] = 0;

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            if(InRange(r + dy[i], c + dx[i]) && dist[r + dy[i]][c + dx[i]] == -1) {
                q.push({r + dy[i], c + dx[i]});
                dist[r + dy[i]][c + dx[i]] = dist[r][c] + 1;
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int row, col;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];

            if(map[i][j] == 1)
                dist[i][j] = -1;
            else if(map[i][j] == 2) {
                row = i;
                col = j;
            }
        }
    }

    BFS(row, col);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << dist[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}