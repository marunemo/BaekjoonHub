#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int coin_count;
    vector<int> coin_case;
    int amount;
    vector<vector<int>> knapsack;

    cin >> tc;
    while(tc--) {
        cin >> coin_count;
        coin_case = vector<int>(coin_count + 1);
        for(int i = 1; i <= coin_count; i++)
            cin >> coin_case[i];

        cin >> amount;
        knapsack = vector<vector<int>>(amount + 1, vector<int>(coin_count + 1, 0));
        for(int coin = 1; coin <= coin_count; coin++) {
            for(int money = 1; money <= amount; money++) {
                knapsack[money][coin] = knapsack[money][coin - 1];
                if(money >= coin_case[coin]) {
                    if(money == coin_case[coin])
                        knapsack[money][coin] += 1;
                    else if(knapsack[money - coin_case[coin]][coin])
                        knapsack[money][coin] += knapsack[money - coin_case[coin]][coin];
                }
            }
        }

        cout << knapsack[amount][coin_count] << '\n';
    }
    return 0;
}