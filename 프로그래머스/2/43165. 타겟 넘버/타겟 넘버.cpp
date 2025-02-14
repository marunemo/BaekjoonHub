#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<vector<int>> DP = vector<vector<int>>(numbers.size() + 1, vector<int>(2001));
    const int OFFSET = 1000;
    
    DP[0][0 + OFFSET] = 1;
    for(int i = 1; i <= numbers.size(); i++) {
        for(int j = -1000; j <= 1000; j++) {
            if(j + OFFSET - numbers[i - 1] >= 0)
                DP[i][j + OFFSET - numbers[i - 1]] += DP[i - 1][j + OFFSET];
            if(j + OFFSET + numbers[i - 1] <= 2000)
                DP[i][j + OFFSET + numbers[i - 1]] += DP[i - 1][j + OFFSET];
        }
    }
    
    answer = DP[numbers.size()][target + OFFSET];
    return answer;
}