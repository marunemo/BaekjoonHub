#include <iostream>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int height, width;
char map[20][20];

int InRange(int row, int col) {
    if(row < 0)
        return false;
    if(row >= height)
        return false;
    if(col < 0)
        return false;
    if(col >= width)
        return false;
    return true;
}

int DFS(int row, int col, int mask) {
    int count = 1;

    mask |= 1 << (map[row][col] - 'A');
    for(int i = 0; i < 4; i++) {
        if(InRange(row + dy[i], col + dx[i]) && !(mask & 1 << (map[row + dy[i]][col + dx[i]] - 'A')))
            count = max(count, DFS(row + dy[i], col + dx[i], mask) + 1);
    }

    return count;
}

int main() {
    cin >> height >> width;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            cin >> map[row][col];
    }

    cout << DFS(0, 0, 0) << endl;
    return 0;
}