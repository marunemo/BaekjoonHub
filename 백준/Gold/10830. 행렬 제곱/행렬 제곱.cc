#include <iostream>
#include <vector>

using namespace std;
using Row = vector<int>;
using Matrix = vector<Row>;

Matrix operator*(Matrix A, Matrix B) {
    int row = A.size();
    int col = B[0].size();
    int mul = B.size();
    Matrix result = Matrix(row, Row(col, 0));

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            for(int k = 0; k < mul; k++)
                result[i][j] += A[i][k] * B[k][j];
            result[i][j] %= 1000;
        }
    }
    return result;
}

int main() {
    int size;
    long long exponent;
    Matrix matrix;
    Matrix result;

    cin >> size >> exponent;
    matrix = Matrix(size, Row(size));
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++)
            cin >> matrix[i][j];
    }

    // identity matrix
    result = Matrix(size, Row(size, 0));
    for(int i = 0; i < size; i++)
        result[i][i] = 1;

    while(exponent) {
        if(exponent & 1)
            result = result * matrix;
        
        matrix = matrix * matrix;
        exponent >>= 1;
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}