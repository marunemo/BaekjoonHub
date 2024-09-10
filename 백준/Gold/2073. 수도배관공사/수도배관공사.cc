#include <iostream>
#include <vector>

using namespace std;

int main() {
    int pipe_count, distance;
    int length, capacity;
    vector<int> dp;

    cin >> distance >> pipe_count;
    dp.resize(distance + 1, 0);

    for(int i = 0; i < pipe_count; i++) {
        cin >> length >> capacity;

        for(int j = distance; j > length; j--) {
            if(dp[j - length])
                dp[j] = max(dp[j], min(dp[j - length], capacity));
        }
        dp[length] = max(dp[length], capacity);
    }

    cout << dp[distance] << endl;
    return 0;
}