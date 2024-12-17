#include <iostream>

using namespace std;

int matrix[1024][1024];

int FindSecond(int start_r, int start_c) {
    int first, second;
    
    // (1, 1)
    first = matrix[start_r][start_c];

    // (1, 2)
    if(first > matrix[start_r][start_c + 1])
        second = matrix[start_r][start_c + 1];
    else {
        second = first;
        first = matrix[start_r][start_c + 1];
    }

    // (2, 1)
    if(first <= matrix[start_r + 1][start_c]) {
        second = first;
        first = matrix[start_r + 1][start_c];
    }
    else if(second < matrix[start_r + 1][start_c]) {
        second = matrix[start_r + 1][start_c];
    }

    // (2, 2)
    if(first <= matrix[start_r + 1][start_c + 1]) {
        second = first;
        first = matrix[start_r + 1][start_c + 1];
    }
    else if(second < matrix[start_r + 1][start_c + 1]) {
        second = matrix[start_r + 1][start_c + 1];
    }

    return second;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, row, col;

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    for(int size = n; size > 1; size /= 2) {
        for(int i = 0; i < size; i += 2) {
            for(int j = 0; j < size; j += 2)
                matrix[i / 2][j / 2] = FindSecond(i, j);
        }
    }

    cout << matrix[0][0] << endl;
    return 0;
}