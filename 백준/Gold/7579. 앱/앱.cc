#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long need;
    cin >> n >> need;

    vector<long> usingByte(n + 1);
    vector<int> cost(n + 1);
    int costSum = 0;
    for(int i = 1; i <= n; i++)
        cin >> usingByte[i];
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
        costSum += cost[i];
    }

    vector<vector<long>> knapsack(n + 1, vector<long>(costSum + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= costSum; j++) {
            knapsack[i][j] = knapsack[i-1][j];
            // 해당 앱을 포함할 시
            if(j - cost[i] >= 0)
                knapsack[i][j] = max(knapsack[i][j], knapsack[i-1][j-cost[i]] + usingByte[i]);
        }
    }

    int minCost;
    for(minCost = 0; knapsack[n][minCost] < need; minCost++);
    cout << minCost << endl;
    return 0;
}