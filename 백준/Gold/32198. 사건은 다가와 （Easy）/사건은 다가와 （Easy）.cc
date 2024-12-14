#include <iostream>
#define OFFSET 1000

using namespace std;
using pii = pair<int, int>;

pii bodybang[1001];
int DP[1001][2001];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, t, a, b;
    int finish_time = 0;
    int min_move;

    cin >> n;
    while(n--) {
        cin >> t >> a >> b;
        bodybang[t] = {a + OFFSET, b + OFFSET};

        if(t > finish_time)
            finish_time = t;
    }

    for(int time = 1; time <= finish_time; time++) {
        for(int i = -time + OFFSET; i <= time + OFFSET; i++) {
            DP[time][i] = -1;
            if(bodybang[time].first < i && i < bodybang[time].second)
                continue;
            
            if(i > -(time - 1) + OFFSET && DP[time - 1][i - 1] != -1) {
                if(DP[time][i] == -1)
                    DP[time][i] = DP[time - 1][i - 1] + 1;
                else
                    DP[time][i] = min(DP[time][i], DP[time - 1][i - 1] + 1);
            }

            if(i >= -(time - 1) + OFFSET && i <= (time - 1) + OFFSET && DP[time - 1][i] != -1) {
                if(DP[time][i] == -1)
                    DP[time][i] = DP[time - 1][i];
                else
                    DP[time][i] = min(DP[time][i], DP[time - 1][i]);
            }

            if(i < (time - 1) + OFFSET && DP[time - 1][i + 1] != -1) {
                if(DP[time][i] == -1)
                    DP[time][i] = DP[time - 1][i + 1] + 1;
                else
                    DP[time][i] = min(DP[time][i], DP[time - 1][i + 1] + 1);
            }
        }
    }

    min_move = finish_time + 1;
    for(int i = -finish_time + OFFSET; i <= finish_time + OFFSET; i++) {
        if(DP[finish_time][i] != -1)
            min_move = min(min_move, DP[finish_time][i]);
    }
    
    if(min_move == finish_time + 1)
        cout << -1 << endl;
    else
        cout << min_move << endl;
    return 0;
}