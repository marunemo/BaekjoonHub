#include <iostream>
#include <vector>

using namespace std;
using Mask = vector<bool>;
using Matrix = vector<Mask>;

const int dx[4] = {-1, -1, 1, 1};
const int dy[4] = {-1, 1, -1, 1};

int table_size;
Matrix table;
Mask slash;
Mask back_slash;

int DFS(int row, int col, int count, bool black) {
    if(row >= table_size)
        return count;
    if(col >= table_size)
        return DFS(row + 1, 0, count, black);
    
    if(black == ((row + col) % 2))
        return DFS(row, col + 1, count, black);
    
    int max_count = DFS(row, col + 1, count, black);
    
    if(!table[row][col] || !(slash[row + col] && back_slash[row - col + 10]))
        return max_count;
    
    slash[row + col] = false;
    back_slash[row - col + 10] = false;
    max_count = max(max_count, DFS(row, col + 1, count + 1, black));
    slash[row + col] = true;
    back_slash[row - col + 10] = true;

    return max_count;
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int checkable;

    cin >> table_size;
    table = Matrix(table_size, Mask(table_size));
    for(int i = 0; i < table_size; i++) {
        for(int j = 0; j < table_size; j++) {
            cin >> checkable;
            table[i][j] = (checkable == 1);
        }
    }

    slash = Mask(21, true);
    back_slash = Mask(21, true);
    cout << (DFS(0, 0, 0, false) + DFS(0, 0, 0, true)) << endl;
    return 0;
}