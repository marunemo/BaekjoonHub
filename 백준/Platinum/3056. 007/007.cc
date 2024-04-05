#include <iostream>

using namespace std;

int n;
double percent[20][20];

double memo[1 << 20];

double dfs(int mask, int bond) {
    if(bond == n)
        return 1;
    
    double &success = memo[mask];
    if(success != -1)
        return success;
    
    success = 0;
    for(int i = 0; i < n; i++) {
        if(!(mask & (1 << i)))
            success = max(success, dfs((mask | (1 << i)), bond + 1) * percent[bond][i]);
    }
    return success;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> percent[i][j];
            percent[i][j] *= 0.01;
        }
    }

    for(int i = 0; i < (1 << n); i++)
        memo[i] = -1;

    // 퍼센트로 출력
    cout.precision(6);
    cout << fixed;
    cout << dfs(0, 0) * 100 << endl;
    return 0;
}