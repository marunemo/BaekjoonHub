#include <iostream>

using namespace std;

int phase_count, heal;
int score[1001];
int damage[1001];
int DP[101] = {0};

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
        for(int j = 100; j >= 0; j--)
            DP[min(100, j + heal)] = max(DP[min(100, j + heal)], DP[j]);
        for(int j = 0; j < heal; j++)
            DP[j] = 0;

        for(int j = damage[i]; j <= 100; j++)
            DP[j - damage[i]] = max(DP[j - damage[i]], DP[j] + score[i]);
    }
    
    for(int i = 0; i <= 100; i++)
        max_score = max(max_score, DP[i]);
    cout << max_score << endl;
    return 0;
}