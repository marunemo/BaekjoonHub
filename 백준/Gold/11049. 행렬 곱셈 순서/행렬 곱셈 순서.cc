#include <iostream>
#define MAX 10000000000

using namespace std;
using ll = long long;

int matrix_count;
ll matrix_size[501];
ll dp[501][501];

int main() {
    int m, n;

    cin >> matrix_count;
    for(int i = 0; i < matrix_count; i++) {
        cin >> m >> n;
        if(i == 0)
            matrix_size[i] = m;
        matrix_size[i + 1] = n;
    }

    for(int diagonal = 1; diagonal <= matrix_count; diagonal++)
        dp[diagonal][diagonal] = 0;

    for(int depth = 1; depth < matrix_count; depth++) {
        for(int diagonal = 1; diagonal <= matrix_count - depth; diagonal++) {
            dp[diagonal][diagonal + depth] = MAX;
            for(int sol = 0; sol < depth; sol++) {
                dp[diagonal][diagonal + depth] = min(
                    dp[diagonal][diagonal + depth],
                    dp[diagonal][diagonal + sol] + dp[diagonal + sol + 1][diagonal + depth]
                        + matrix_size[diagonal - 1] * matrix_size[diagonal + sol] * matrix_size[diagonal + depth]
                );
            }
        }
    }
    
    cout << dp[1][matrix_count] << endl;
    return 0;
}