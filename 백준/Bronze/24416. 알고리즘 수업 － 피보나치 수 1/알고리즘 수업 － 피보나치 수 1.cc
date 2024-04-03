#include <iostream>

using namespace std;

int memo[41] = {1, 1, 1, 0};

int FiboCount(int n) {
    if(memo[n])
        return memo[n];
    
    return FiboCount(n - 1) + FiboCount(n - 2);
}

int main() {
    int n;

    cin >> n;

    cout << FiboCount(n) << ' ' << (n - 2) << endl;
    return 0;
}