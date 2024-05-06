#include <iostream>
#include <vector>

using namespace std;
using RowVec = vector<bool>;
using Matrix = vector<RowVec>;

int main() {
    int size;
    int input;
    Matrix adj_matrix;

    cin >> size;
    adj_matrix = Matrix(size, RowVec(size));
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cin >> input;
            adj_matrix[i][j] = (input == 1);
        }
    }

    for(int mid = 0; mid < size; mid++) {
        for(int start = 0; start < size; start++) {
            for(int end = 0; end < size; end++)
                adj_matrix[start][end] = adj_matrix[start][end] | (adj_matrix[start][mid] & adj_matrix[mid][end]);
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++)
            cout << (adj_matrix[i][j] ? 1 : 0) << ' ';
        cout << '\n';
    }
    return 0;
}