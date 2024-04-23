#include <iostream>

using namespace std;

bool knapsack[15001] = {0};

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int weight_count;
    int weight;
    int weight_sum = 0;
    int query;
    int marble;
    bool flag;

    cin >> weight_count;

    knapsack[0] = true;
    while(weight_count--) {
        cin >> weight;
        weight_sum += weight;

        for(int sum = weight_sum; sum >= weight; sum--) {
            if(knapsack[sum - weight])
                knapsack[sum] = true;
        }
    }

    cin >> query;
    while(query--) {
        cin >> marble;
        
        flag = false;
        for(weight = marble; weight <= weight_sum && !flag; weight++) {
            if(knapsack[weight] && knapsack[weight - marble])
                flag = true;
        }

        if(flag)
            cout << "Y ";
        else
            cout << "N ";
    }

    cout << endl;
    return 0;
}