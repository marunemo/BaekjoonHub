#include <iostream>
#define INF 10000000

using namespace std;

int main() {
    int n;
    char block[1000];
    int memo[1000];

    cin >> n;

    cin >> block[0];
    memo[0] = 0;

    for(int i = 1; i < n; i++) {
        cin >> block[i];

        memo[i] = INF;
        for(int j = i - 1; j >= 0; j--) {
            if(block[i] == 'B' && block[j] == 'J' && memo[j] != INF)
                memo[i] = min(memo[i], memo[j] + (i - j) * (i - j));
            else if(block[i] == 'O' && block[j] == 'B' && memo[j] != INF)
                memo[i] = min(memo[i], memo[j] + (i - j) * (i - j));
            else if(block[i] == 'J' && block[j] == 'O' && memo[j] != INF)
                memo[i] = min(memo[i], memo[j] + (i - j) * (i - j));
        }
    }

    if(memo[n - 1] == INF)
        cout << -1 << endl;
    else
        cout << memo[n - 1] << endl;
    return 0;
}