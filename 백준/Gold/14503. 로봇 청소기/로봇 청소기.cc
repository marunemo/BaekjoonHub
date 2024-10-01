#include <iostream>
#include <vector>

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool InRange(int const &n, int const &m, int row, int col) {
    return !(row < 0 || col < 0 || row >= n || col >= m);
}

void Simulate(vector<vector<bool>> &map, vector<vector<bool>> &clean, int const &n, int const &m, int row, int col, int dir) {
    if(!InRange(n, m, row, col) || map[row][col])
        return;
    clean[row][col] = true;

    bool dirty = false;
    int next_dir;
    for(int i = 1; i <= 4 && !dirty; i++) {
        next_dir = (dir - i + 4) % 4;
        if(!InRange(n, m, row + dy[next_dir], col + dx[next_dir]))
            continue;

        if(!map[row + dy[next_dir]][col + dx[next_dir]] && !clean[row + dy[next_dir]][col + dx[next_dir]]) {
            dirty = true;
            Simulate(map, clean, n, m, row + dy[next_dir], col + dx[next_dir], next_dir);
        }
    }

    if(!dirty)
        Simulate(map, clean, n, m, row - dy[dir], col - dx[dir], dir);
}

int main() {
    int n, m;
    int row, col, dir;
    vector<vector<bool>> map;
    vector<vector<bool>> clean;
    int status;
    int count = 0;

    cin >> n >> m;
    cin >> row >> col >> dir;

    map.resize(n, vector<bool>(m));
    clean.resize(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> status;
            map[i][j] = status == 1;
        }
    }

    Simulate(map, clean, n, m, row, col, dir);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            count += clean[i][j];
    }

    cout << count << endl;
    return 0;
}