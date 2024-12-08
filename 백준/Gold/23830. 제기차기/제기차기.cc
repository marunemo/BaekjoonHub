#include <iostream>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int student_count;
    int score, max_score = 0;
    ll p, q, r, S;
    ll total_score = 0;
    int K;
    int count[100001] = {0};

    cin >> student_count;
    for(int i = 0; i < student_count; i++) {
        cin >> score;
        
        count[score]++;

        total_score += score;
        max_score = max(score, max_score);
    }
    cin >> p >> q >> r >> S;

    for(int i = r + 1; i <= max_score; i++)
        total_score -= (ll)p * count[i];

    for(K = 1; K <= max_score + 1; K++) {
        total_score += (ll)q * count[K - 1];
        if(K + r <= max_score)
            total_score += (ll)p * count[K + r];
        if(total_score >= S)
            break;
    }

    if(total_score < S)
        K = -1;

    cout << K << endl;
    return 0;
}