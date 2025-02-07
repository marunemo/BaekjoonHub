#include <iostream>

using namespace std;

const int dr[4] = {-1, 0, 1, 1};
const int dc[4] = {1, 1, 1, 0};

char board[20][20] = {0};

int GomokuCount(int row, int col, int dir, bool right) {
    int horizontal = 2 * right - 1;
    int count = 0;

    if(row + horizontal * dr[dir] > 0 && row + horizontal * dr[dir] < 20 && col + horizontal * dc[dir] > 0 && col + horizontal * dc[dir] < 20) {
        if(board[row][col] == board[row + horizontal * dr[dir]][col + horizontal * dc[dir]])
            count = GomokuCount(row + horizontal * dr[dir], col + horizontal * dc[dir], dir, right) + 1;
    }
    return count;
}

int main() {
    int num;
    int row, col;
    int end = -1;

    cin >> num;
    for(int i = 1; i <= num; i++) {
        cin >> row >> col;
        board[row][col] = i % 2 + 1;
        for(int dir = 0; dir < 4; dir++) {
            if(GomokuCount(row, col, dir, true) + GomokuCount(row, col, dir, false) + 1 == 5) {
                if(end == -1)
                    end = i;
            }
        }
    }
    cout << end << endl;
    return 0;
}