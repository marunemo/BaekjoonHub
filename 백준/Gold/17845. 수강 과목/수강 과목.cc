#include <iostream>

using namespace std;

int knapsack[10001];

int main() {
    int max_time, sub_count;
    int importance, time;

    cin >> max_time >> sub_count;
    while(sub_count--) {
        cin >> importance >> time;

        for(int t = max_time; t >= time; t--)
            knapsack[t] = max(knapsack[t], knapsack[t - time] + importance);
    }

    cout << knapsack[max_time] << endl;
    return 0;
}