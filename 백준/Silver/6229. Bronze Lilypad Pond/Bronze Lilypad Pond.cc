#include <iostream>
#include <queue>

using namespace std;

const int d_m1[4] = {1, 1, -1, -1};
const int d_m2[4] = {1, -1, 1, -1};

int n, m, m1, m2;
int map[30][30];
int path[30][30];
queue<pair<int, int>> q;

bool Valid(int row, int col) {
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

int BFS(int row, int col) {
    int next_row, next_col;

    q.push({row, col});
    map[row][col] = 0;

    while(!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            next_row = row + d_m1[i] * m1;
            next_col = col + d_m2[i] * m2;

            if(!Valid(next_row, next_col))
                continue;
            if(map[next_row][next_col] == 4)
                return path[row][col] + 1;
            if(map[next_row][next_col] == 1 && !path[next_row][next_col]) {
                path[next_row][next_col] = path[row][col] + 1;
                q.push({next_row, next_col});
            }
        }
        for(int i = 0; i < 4; i++) {
            next_row = row + d_m2[i] * m2;
            next_col = col + d_m1[i] * m1;

            if(!Valid(next_row, next_col))
                continue;
            if(map[next_row][next_col] == 4)
                return path[row][col] + 1;
            if(map[next_row][next_col] == 1 && !path[next_row][next_col]) {
                path[next_row][next_col] = path[row][col] + 1;
                q.push({next_row, next_col});
            }
        }
    }

    return 10000;
}

int main() {
    int row, col;

    cin >> n >> m >> m1 >> m2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 3) {
                row = i;
                col = j;
            }

            path[i][j] = 0;
        }
    }

    cout << BFS(row, col) << endl;
    return 0;
}