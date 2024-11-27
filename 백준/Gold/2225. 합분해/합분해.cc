#include <iostream>
#define MOD 1000000000

using namespace std;

int dp[201][201] = {0};

int main() {
    int n, k;

    cin >> n >> k;

    dp[0][0] = 1;
    for(int count = 1; count <= k; count++) {
        for(int sum = 0; sum <= n; sum++) {
            for(int add = 0; add <= 200; add++) {
                if(sum - add < 0)
                    continue;
                
                dp[count][sum] = (dp[count][sum] + dp[count - 1][sum - add]) % MOD;
            }
        }
    }

    cout << dp[k][n] << endl;
    return 0;
}