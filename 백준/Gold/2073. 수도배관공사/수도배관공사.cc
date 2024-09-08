#include <iostream>

using namespace std;
using Pipe = pair<int, int>;

Pipe pipe[351];
int knapsack[100001] = {0};

int main() {
    int distance, pipe_count;

    cin >> distance >> pipe_count;
    for(int i = 1; i <= pipe_count; i++)
        cin >> pipe[i].first >> pipe[i].second;
    
    for(int i = 1; i <= pipe_count; i++) {
        for(int length = distance; length > pipe[i].first; length--) {
            if(knapsack[length - pipe[i].first])
                knapsack[length] = max(knapsack[length], min(pipe[i].second, knapsack[length - pipe[i].first]));
        }
        knapsack[pipe[i].first] = max(knapsack[pipe[i].first], pipe[i].second);
    }

    cout << knapsack[distance] << endl;
    return 0;
}