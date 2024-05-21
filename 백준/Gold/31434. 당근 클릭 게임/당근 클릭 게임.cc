#include <iostream>

using namespace std;

int cost[100];
int bonus[100];
int memo[101][5001];

int main() {
    int n, k;
    int max_bonus = 0;
    int max_carrot = 0;

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> cost[i] >> bonus[i];
        max_bonus = max(max_bonus, bonus[i]);
    }

    for(int second = 0; second < k; second++) {
        for(int carrot = 0; carrot <= max_bonus * k; carrot++)
            memo[second][carrot] = -1;
    }
    memo[0][1] = 0;

    for(int second = 0; second < k; second++) {
        for(int carrot = 0; carrot <= max_bonus * k; carrot++) {
            if(memo[second][carrot] == -1)
                continue;

            memo[second + 1][carrot] = max(memo[second + 1][carrot], memo[second][carrot] + carrot);
            for(int item = 0; item < n; item++) {
                if(memo[second][carrot] >= cost[item])
                    memo[second + 1][carrot + bonus[item]] = max(memo[second + 1][carrot + bonus[item]], memo[second][carrot] - cost[item]);
            }
        }
    }

    for(int carrot = 0; carrot <= max_bonus * k; carrot++)
        max_carrot = max(max_carrot, memo[k][carrot]);
    cout << max_carrot << endl;
    return 0;
}