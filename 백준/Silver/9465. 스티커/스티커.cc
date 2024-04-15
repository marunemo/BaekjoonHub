#include <iostream>

using namespace std;

int sticker[100000][2];
int memo[100000][3];

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc, n;

    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> sticker[i][0];
        for(int i = 0; i < n; i++)
            cin >> sticker[i][1];

        memo[0][0] = sticker[0][0];
        memo[0][1] = sticker[0][1];
        memo[0][2] = 0;
        for(int i = 1; i < n; i++) {
            memo[i][0] = max(memo[i-1][1], memo[i-1][2]) + sticker[i][0];
            memo[i][1] = max(memo[i-1][0], memo[i-1][2]) + sticker[i][1];
            memo[i][2] = max(memo[i-1][0], memo[i-1][1]);
            memo[i][2] = max(memo[i][2], memo[i-1][2]);
        }
        cout << max(max(memo[n-1][0], memo[n-1][1]), memo[n-1][2]) << '\n';
    }
}