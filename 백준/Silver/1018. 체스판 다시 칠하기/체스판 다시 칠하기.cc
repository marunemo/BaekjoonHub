#include <iostream>

using namespace std;

char chess[50][50];

int CheckChess(char color, int start_row, int start_col) {
    int count = 0;
    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            if((row + col) % 2)
                count += (chess[start_row + row][start_col + col] == color);
            else
                count += (chess[start_row + row][start_col + col] != color);
        }
    }
    return count;
}

int main() {
    int m, n;
    char color;
    int min_count = 10000;

    cin >> n >> m;
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            cin >> color;
            chess[row][col] = color;
        }
    }

    for(int row = 0; row <= n - 8; row++) {
        for(int col = 0; col <= m - 8; col++) {
            min_count = min(min_count, CheckChess('B', row, col));
            min_count = min(min_count, CheckChess('W', row, col));
        }
    }
    cout << min_count << endl;
    return 0;
}