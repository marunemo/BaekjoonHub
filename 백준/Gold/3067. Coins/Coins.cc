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
    vector<int> knapsack;

    cin >> tc;
    while(tc--) {
        cin >> coin_count;
        coin_case = vector<int>(coin_count + 1);
        for(int i = 1; i <= coin_count; i++)
            cin >> coin_case[i];

        cin >> amount;
        knapsack = vector<int>(amount + 1, 0);
        knapsack[0] = 1;    // 0을 표현하는 가지 수
        for(int coin = 1; coin <= coin_count; coin++) {
            for(int money = coin_case[coin]; money <= amount; money++) {
                knapsack[money] += knapsack[money - coin_case[coin]];
            }
        }

        cout << knapsack[amount] << '\n';
    }
    return 0;
}