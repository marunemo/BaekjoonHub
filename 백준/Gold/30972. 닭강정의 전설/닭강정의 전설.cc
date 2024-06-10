#include <iostream>

using namespace std;

int chicken[5001][5001];
int prefix_sum[5001][5001];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int size;
    int query;
    int r1, c1, r2, c2;
    int degree;
    
    cin >> size;
    for(int i = 0; i <= size; i++)
        prefix_sum[i][0] = prefix_sum[0][i] = 0;

    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= size; j++) {
            cin >> chicken[i][j];
            prefix_sum[i][j] = prefix_sum[i][j - 1] + chicken[i][j];
        }

        for(int j = 1; j <= size; j++)
            prefix_sum[i][j] += prefix_sum[i - 1][j];
    }

    cin >> query;
    while(query--) {
        cin >> r1 >> c1 >> r2 >> c2;

        degree = 0;
        degree -= prefix_sum[r2][c2] - prefix_sum[r2][c1 - 1] - prefix_sum[r1 - 1][c2] + prefix_sum[r1 - 1][c1 - 1];
        degree += (prefix_sum[r2 - 1][c2 - 1] - prefix_sum[r2 - 1][c1] - prefix_sum[r1][c2 - 1] + prefix_sum[r1][c1]) * 2;

        cout << degree << '\n';
    }
    return 0;
}