#include <iostream>
#define MOD 1000000007

using namespace std;
using ll = long long;
using Vec = pair<ll, ll>;
using Matrix = pair<Vec, Vec>;

Matrix fibonacci = {{1, 1}, {1, 0}};

Matrix MatrixMultiple(Matrix a, Matrix b) {
    Matrix result = {
        {
            (a.first.first * b.first.first + a.first.second * b.second.first) % MOD,
            (a.first.first * b.first.second + a.first.second * b.second.second) % MOD
        },
        {
            (a.second.first * b.first.first + a.second.second * b.second.first) % MOD,
            (a.second.first * b.first.second + a.second.second * b.second.second) % MOD
        }
    };
    return result;
}

Matrix DivideAndConquer(ll power) {
    if(power == 1)
        return fibonacci;
    
    Matrix sub_solution = DivideAndConquer(power / 2);
    Matrix solution = MatrixMultiple(sub_solution, sub_solution);

    if(power % 2)
        return MatrixMultiple(solution, fibonacci);
    return solution;
}

int main() {
    ll index;

    cin >> index;
    
    index -= (index % 2);
    if(!index)
        cout << 0 << endl;
    else
        cout << (DivideAndConquer(index).first.first - 1) << endl;
    return 0;
}