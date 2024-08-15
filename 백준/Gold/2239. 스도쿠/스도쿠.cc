#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));

bool valid(int row, int col) {
    int trow = row / 3 * 3;
    int tcol = col / 3 * 3;
    for(int i = 0; i < 9; i++) {
        if(row != i && sudoku[row][col] == sudoku[i][col])
            return false;
    }
    for(int i = 0; i < 9; i++) {
        if(col != i && sudoku[row][col] == sudoku[row][i])
            return false;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(trow + i == row && tcol + j == col)
                continue;
            if(sudoku[trow + i][tcol + j] == sudoku[row][col])
                return false;
        }
    }
    return true;
}

bool solve(int row, int col) {
    if(row == 9) return true;
    if(col == 9) return solve(row + 1, 0);
    if(sudoku[row][col] != 0) return solve(row, col + 1);

    for(int i = 1; i <= 9; i++) {
        sudoku[row][col] = i;
        if(valid(row, col)) {
            if(solve(row, col + 1))
                return true;
        }
    }
    sudoku[row][col] = 0;
    return false;
}

int main() {
    // Fast IO
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    vector<string> input(9);
    for(int i = 0; i < 9; i++)
        cin >> input[i];
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++)
            sudoku[i][j] = input[i][j] - '0';
    }

    solve(0, 0);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++)
            cout << sudoku[i][j];
        cout << '\n';
    }
    return 0;
}