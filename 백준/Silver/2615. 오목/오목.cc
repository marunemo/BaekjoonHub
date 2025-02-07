#include <iostream>

using namespace std;

const int dr[4] = {0, 1, 1, -1};
const int dc[4] = {1, 0, 1, 1};

int board[20][20];

int GomokuCount(int row, int col, int dir, int color) {
    if(row + dr[dir] == 20 || col + dc[dir] == 0 || col + dc[dir] == 20)
        return 0;
    if(board[row + dr[dir]][col + dc[dir]] == color)
        return GomokuCount(row + dr[dir], col + dc[dir], dir, color) + 1;
    return 0;
}

int main() {
    int win = 0;
    int win_row, win_col;

    for(int row = 1; row <= 19; row++) {
        for(int col = 1; col <= 19; col++)
            cin >> board[row][col];
    }

    for(int row = 1; row <= 19 && !win; row++) {
        for(int col = 1; col <= 19 && !win; col++) {
            for(int dir = 0; dir < 4; dir++) {
                if(board[row][col] && (row - dr[dir] == 0 || row - dr[dir] == 20 || col - dc[dir] == 0 || board[row - dr[dir]][col - dc[dir]] != board[row][col])) {
                    if(GomokuCount(row, col, dir, board[row][col]) + 1 == 5) {
                        win = board[row][col];
                        win_row = row, win_col = col;
                    }
                }
            }
        }
    }

    cout << win << '\n';
    if(win)
        cout << win_row << ' ' << win_col << '\n';
    return 0;
}