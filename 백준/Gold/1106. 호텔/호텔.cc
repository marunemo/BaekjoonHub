#include <iostream>
#include <vector>
#define INF 1000000

using namespace std;

int main() {
    int c, n;
    cin >> c >> n;

    int min_cost = INF;
    vector<int> memo(c, INF);
    memo[0] = 0;

    int cost;
    int value;
    for(int i = 0; i < n; i++) {
        cin >> cost >> value;
        
        for(int j = value; j < c; j++) {
            if(memo[j - value] != INF)
                memo[j] = min(memo[j], memo[j - value] + cost);
        }
        for(int j = 0; j < value; j++) {
            if(memo[j - value] != INF)
               min_cost = min(min_cost, memo[c - value + j] + cost);
        }
    }

    cout << min_cost << endl;
    return 0;
}