#include <iostream>

using namespace std;

bool map[11][11];

bool IsSafe(int row, int col, int n) {
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            if(!map[row + r][col + c])
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc, r, c, k, ri, ci;
    int count;

    cin >> tc;
    for(int num = 1; num <= tc; num++) {
        cin >> r >> c >> k;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++)
                map[i][j] = true;
        }

        while(k--) {
            cin >> ri >> ci;
            map[ri][ci] = false;
        }

        count = 0;
        for(int n = 1; n <= min(r, c); n++) {
            for(int i = 0; i < r - n + 1; i++) {
                for(int j = 0; j < c - n + 1; j++)
                    count += IsSafe(i, j, n);
            }
        }

        cout << "Case #" << num << ": " << count << '\n';
    }
    return 0;
}