#include <iostream>

using namespace std;

int n, m, k;
int sell[301][10001];
pair<int, int> best[10001];
int best_count[301];
int q;
int king = 0;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int j, t;
    int i, v;

    cin >> n >> m >> k;
    for(int emp = 1; emp <= n; emp++) {
        for(int i = 0; i < k; i++) {
            cin >> j >> t;

            sell[emp][j] = t;
            if(best[j].first <= t)
                best[j] = {t, emp};
        }
    }

    for(int i = 1; i <= m; i++) {
        if(best[i].second)
            best_count[best[i].second]++;
    }

    for(int emp = 1; emp <= n; emp++) {
        if(best_count[emp] == k)
            king++;
    }

    cin >> q;
    while(q--) {
        cin >> i >> j >> v;

        sell[i][j] += v;
        if(best[j].first <= sell[i][j]) {
            if(best[j].second != i) {
                if((++best_count[i]) == k)
                    king++;
                if((best_count[best[j].second]--) == k)
                    king--;
            }

            best[j] = {sell[i][j], i};
        }

        cout << king << '\n';
    }
    return 0;
}