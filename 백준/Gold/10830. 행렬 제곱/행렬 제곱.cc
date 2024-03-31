#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using Column = vector<int>;
using Matrix = vector<Column>;

Matrix MatrixMultiple(Matrix a, Matrix b) {
    int row_size = a.size();
    int col_size = b[0].size();
    int mul_size = a[0].size();
    Matrix result = Matrix(row_size, Column(col_size));

    for(int row = 0; row < row_size; row++) {
        for(int col = 0; col < col_size; col++) {
            result[row][col] = 0;
            for(int mul = 0; mul < mul_size; mul++)
                result[row][col] += a[row][mul] * b[mul][col];
            result[row][col] %= 1000;
        }
    }
    return result;
}

Matrix DivideAndConquer(Matrix mat, ll power) {
    if(power == 1)
        return mat;

    Matrix sub_solution = DivideAndConquer(mat, power / 2);
    Matrix solution = MatrixMultiple(sub_solution, sub_solution);
    
    if(power % 2)
        return MatrixMultiple(solution, mat);
    return solution;
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int size;
    ll power;
    Matrix mat, solution;

    cin >> size >> power;
    mat = Matrix(size, Column(size));
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            cin >> mat[row][col];
            mat[row][col] %= 1000;
        }
    }

    solution = DivideAndConquer(mat, power);
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++)
            cout << solution[row][col] << ' ';
        cout << '\n';
    }
    return 0;
}