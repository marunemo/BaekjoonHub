#include <iostream>

using namespace std;

int n;
int map[16][16];

int DFS(int row, int col, int dir) {
    if(row == n)
        return false;
    if(col == n)
        return false;
    if(dir != 2 && map[row][col])
        return false;
    if(dir == 2 && (map[row][col] || map[row - 1][col] || map[row][col - 1]))
        return false;
    if(row == n - 1 && col == n - 1)
        return true;

    int count = 0;
    if(dir == 0)
        count += DFS(row, col + 1, 0) + DFS(row + 1, col + 1, 2);
    else if(dir == 1)
        count += DFS(row + 1, col, 1) + DFS(row + 1, col + 1, 2);
    else if(dir == 2)
        count += DFS(row, col + 1, 0) + DFS(row + 1, col, 1) + DFS(row + 1, col + 1, 2);
    return count;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    cout << DFS(0, 1, 0) << endl;
    return 0;
}