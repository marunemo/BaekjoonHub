#include <iostream>

using namespace std;

int DP[10001][501] = {0};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int time, score;

    cin >> time >> score;
    for(int dist, t = 1; t <= time; t++) {
        cin >> dist;
        for(int s = score; s > 0; s--) {
            if(t < s)
                continue;

            DP[t][s] = DP[t - 1][s - 1] + dist;
            if(t + s <= time)
                DP[t + s][0] = max(DP[t + s][0], DP[t][s]);
        }
        DP[t][0] = max(DP[t - 1][0], DP[t][0]);
    }

    cout << DP[time][0] << endl;
    return 0;
}