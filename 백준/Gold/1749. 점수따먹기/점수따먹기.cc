#include <iostream>

using namespace std;

int n, m;
int matrix[201][201];
int prefix[201][201];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int max_sum = -800000000;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cin >> matrix[i][j];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            prefix[i][j] = matrix[i][j] + prefix[i][j - 1];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            prefix[i][j] += prefix[i - 1][j];
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int i_s = 0; i_s < i; i_s++) {
                for(int j_s = 0; j_s < j; j_s++)
                    max_sum = max(max_sum, prefix[i][j] - prefix[i_s][j] - prefix[i][j_s] + prefix[i_s][j_s]);
            }
        }
    }

    cout << max_sum << endl;
    return 0;
}