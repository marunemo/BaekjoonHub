#include <iostream>

using namespace std;

int dp[15000001] = {0};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, t, p;
    int max_value = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t >> p;
        
        dp[i] = max(dp[i], dp[i - 1]);
        if(i + t <= n)
            dp[i + t] = max(dp[i + t], dp[i] + p);
        max_value = max(max_value, dp[i]);
    }
    max_value = max(max_value, dp[n]);

    cout << max_value << endl;
    return 0;
}