#include <iostream>

using namespace std;

int phase_count, heal;
int score[1001];
int damage[1001];
int DP[1001][101] = {0};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int max_score = 0;

    cin >> phase_count >> heal;
    for(int i = 1; i <= phase_count; i++)
        cin >> score[i];
    for(int i = 1; i <= phase_count; i++)
        cin >> damage[i];
    
    for(int i = 1; i <= phase_count; i++) {
        for(int j = 100 - heal; j < 100; j++)
            DP[i - 1][100] = max(DP[i - 1][100], DP[i - 1][j]);
        for(int j = 100 - heal - 1; j >= 0; j--)
            DP[i - 1][j + heal] = DP[i - 1][j];
        for(int j = 0; j < heal; j++)
            DP[i - 1][j] = 0;

        for(int j = 0; j <= 100; j++)
            DP[i][j] = DP[i - 1][j];

        for(int j = damage[i]; j <= 100; j++)
            DP[i][j - damage[i]] = max(DP[i][j - damage[i]], DP[i - 1][j] + score[i]);
    }
    
    for(int i = 0; i <= 100; i++)
        max_score = max(max_score, DP[phase_count][i]);
    cout << max_score << endl;
    return 0;
}