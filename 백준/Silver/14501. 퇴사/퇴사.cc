#include <iostream>

using namespace std;

int main() {
    int due;
    int term[15];
    int price[15];
    int dp[16] = {0};

    cin >> due;
    for(int i = 0; i < due; i++) {
        cin >> term[i] >> price[i];

        if(i > 0)
            dp[i] = max(dp[i], dp[i - 1]);

        if(i + term[i] <= due)
            dp[i + term[i]] = max(dp[i + term[i]], dp[i] + price[i]);
    }
    dp[due] = max(dp[due], dp[due - 1]);

    cout << dp[due] << endl;
    return 0;
}