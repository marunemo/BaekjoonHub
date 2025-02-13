#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    vector<vector<int>> knapsack = vector<vector<int>>(info.size() + 1, vector<int>(m));
    int sum_a = 0;
    
    for(int i = 0; i < info.size(); i++) {
        sum_a += info[i][0];
        for(int j = 0; j < m; j++) {
            knapsack[i + 1][j] = knapsack[i][j];
            if(j >= info[i][1])
                knapsack[i + 1][j] = max(knapsack[i + 1][j], knapsack[i][j - info[i][1]] + info[i][0]);
        }
    }
    
    answer = sum_a - knapsack[info.size()][m - 1];
    if(answer >= n)
        answer = -1;
    
    return answer;
}