#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int candy_count;
    double money;
    int range;
    int calory;
    double price;
    int cent;
    vector<int> knapsack;

    cin >> candy_count >> money;
    while(candy_count != 0 || money != 0) {
        range = money * 100 + 0.5;
        knapsack = vector<int>(range + 1, 0);
        while(candy_count--) {
            cin >> calory >> price;
            cent = price * 100 + 0.5;
            for(int weight = cent; weight <= range; weight++)
                knapsack[weight] = max(knapsack[weight], knapsack[weight - cent] + calory);
        }
        cout << knapsack[range] << '\n';
        cin >> candy_count >> money;
    }
}