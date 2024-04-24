#include <iostream>

using namespace std;

int main() {
    int item_count, total_weight;
    int weight, benefit;
    int knapsack[10001] = {0};

    cin >> item_count >> total_weight;
    while(item_count--) {
        cin >> weight >> benefit;

        for(int capacity = total_weight; capacity >= weight; capacity--)
            knapsack[capacity] = max(knapsack[capacity], knapsack[capacity - weight] + benefit);
    }

    cout << knapsack[total_weight] << endl;
    return 0;
}