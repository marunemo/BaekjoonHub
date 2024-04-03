#include <iostream>

using namespace std;


int main() {
    int n;
    int memo[41] = {1, 1, 1, 0};

    cin >> n;

    for(int i = 3; i <= n; i++)
        memo[i] = memo[i - 1] + memo[i - 2];
    cout << memo[n] << ' ' << (n - 2) << endl;
    return 0;
}