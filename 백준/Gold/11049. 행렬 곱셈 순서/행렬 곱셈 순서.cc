#include <iostream>
#define MAX 2147483647

using namespace std;

int m_count;
int m_size[501];
int dp[501][501] = {0};

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> m_count;
    for(int i = 0; i < m_count; i++)
        cin >> m_size[i] >> m_size[i + 1];

    for(int depth = 2; depth <= m_count; depth++) {
        for(int row = 1; row <= m_count - depth + 1; row++) {
            int col = row + depth - 1;
            dp[row][col] = MAX;
            for(int slice = row; slice < col; slice++)
                dp[row][col] = min(dp[row][col], dp[row][slice] + dp[slice + 1][col] + m_size[row - 1] * m_size[slice] * m_size[col]);
        }
    }
    
    cout << dp[1][m_count] << endl;
    return 0;
}