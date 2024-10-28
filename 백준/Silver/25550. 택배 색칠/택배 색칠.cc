#include <iostream>

using namespace std;
using ll = long long;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int box[1002][1002];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, min_box;
    ll count = 0;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cin >> box[i][j];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            min_box = (box[i][j] ? box[i][j] - 1 : 0);
            for(int k = 0; k < 4; k++)
                min_box = min(min_box, box[i + dy[k]][j + dx[k]]);
            count += min_box;
        }
    }
    cout << count << endl;
    return 0;
}