#include <iostream>

using namespace std;

int knapsack[100001] = {0};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int distance, pipe_count;
    int pipe_len, pipe_cap;

    cin >> distance >> pipe_count;
    for(int i = 1; i <= pipe_count; i++) {
        cin >> pipe_len >> pipe_cap;
        for(int length = distance; length > pipe_len; length--) {
            if(knapsack[length - pipe_len])
                knapsack[length] = max(knapsack[length], min(pipe_cap, knapsack[length - pipe_len]));
        }
        knapsack[pipe_len] = max(knapsack[pipe_len], pipe_cap);
    }

    cout << knapsack[distance] << endl;
    return 0;
}