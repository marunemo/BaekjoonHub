#include <iostream>
#include <vector>

using namespace std;
using Board = vector<vector<int>>;
using Merged = vector<vector<bool>>;

Board MoveUp(Board board) {
    int height = board.size();
    int width = board[0].size();
    Merged check = Merged(height, vector<bool>(width, false));

    for(int row = 1; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(board[row][col] == 0)
                continue;
                
            for(int d_row = row; d_row > 0; d_row--) {
                if(board[d_row - 1][col] == 0) {
                    board[d_row - 1][col] = board[d_row][col];
                    board[d_row][col] = 0;
                }
                else if(board[d_row - 1][col] == board[d_row][col] && !check[d_row - 1][col]) {
                    board[d_row - 1][col] += board[d_row][col];
                    board[d_row][col] = 0;
                    check[d_row - 1][col] = true;
                    break;
                }
                else break;
            }
        }
    }
    return board;
}

Board MoveDown(Board board) {
    int height = board.size();
    int width = board[0].size();
    Merged check = Merged(height, vector<bool>(width, false));

    for(int row = height - 2; row >= 0; row--) {
        for(int col = 0; col < width; col++) {
            if(board[row][col] == 0)
                continue;

            for(int d_row = row; d_row < height - 1; d_row++) {
                if(board[d_row + 1][col] == 0) {
                    board[d_row + 1][col] = board[d_row][col];
                    board[d_row][col] = 0;
                }
                else if(board[d_row + 1][col] == board[d_row][col] && !check[d_row + 1][col]) {
                    board[d_row + 1][col] += board[d_row][col];
                    board[d_row][col] = 0;
                    check[d_row + 1][col] = true;
                    break;
                }
                else break;
            }
        }
    }
    return board;
}

Board MoveLeft(Board board) {
    int height = board.size();
    int width = board[0].size();
    Merged check = Merged(height, vector<bool>(width, false));

    for(int col = 1; col < width; col++) {
        for(int row = 0; row < height; row++) {
            if(board[row][col] == 0)
                continue;
                
            for(int d_col = col; d_col > 0; d_col--) {
                if(board[row][d_col - 1] == 0) {
                    board[row][d_col - 1] = board[row][d_col];
                    board[row][d_col] = 0;
                }
                else if(board[row][d_col - 1] == board[row][d_col] && !check[row][d_col - 1]) {
                    board[row][d_col - 1] += board[row][d_col];
                    board[row][d_col] = 0;
                    check[row][d_col - 1] = true;
                    break;
                }
                else break;
            }
        }
    }
    return board;
}

Board MoveRight(Board board) {
    int height = board.size();
    int width = board[0].size();
    Merged check = Merged(height, vector<bool>(width, false));

    for(int col = width - 2; col >= 0; col--) {
        for(int row = 0; row < height; row++) {
            if(board[row][col] == 0)
                continue;
                
            for(int d_col = col; d_col < width - 1; d_col++) {
                if(board[row][d_col + 1] == 0) {
                    board[row][d_col + 1] = board[row][d_col];
                    board[row][d_col] = 0;
                }
                else if(board[row][d_col + 1] == board[row][d_col] && !check[row][d_col + 1]) {
                    board[row][d_col + 1] += board[row][d_col];
                    board[row][d_col] = 0;
                    check[row][d_col + 1] = true;
                    break;
                }
                else break;
            }
        }
    }
    return board;
}

int GetBiggest(Board board) {
    int height = board.size();
    int width = board[0].size();
    int max_block = 0;

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            max_block = max(max_block, board[row][col]);
    }
    return max_block;
}

int DFS(Board board, int depth) {
    if(depth == 5)
        return GetBiggest(board);
    
    int max_block = 0;
    max_block = max(max_block, DFS(MoveUp(board), depth + 1));
    max_block = max(max_block, DFS(MoveDown(board), depth + 1));
    max_block = max(max_block, DFS(MoveLeft(board), depth + 1));
    max_block = max(max_block, DFS(MoveRight(board), depth + 1));
    return max_block;
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    Board board;

    cin >> n;
    board = Board(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    cout << DFS(board, 0) << endl;
    return 0;
}