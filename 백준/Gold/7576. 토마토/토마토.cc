#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int tomato[1000][1000];

bool CheckTomato(int m, int n) {
    for(int row = 0; row < m; row++) {
        for(int col = 0; col < n; col++) {
            if(tomato[row][col] == 0)
                return false;
        }
    }
    return true;
}

int main() {
    // FAST I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    queue<pii> current;
    queue<pii> next;
    int date;

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> tomato[i][j];
            if(tomato[i][j] == 1)
                current.push({i, j});
        }
    }

    date = 0;
    while(!current.empty()) {
        auto [row, col] = current.front();
        current.pop();

        if(row > 0 && tomato[row - 1][col] == 0) {
            tomato[row - 1][col] = 1;
            next.push({row - 1, col});
        }
        if(row < m - 1 && tomato[row + 1][col] == 0) {
            tomato[row + 1][col] = 1;
            next.push({row + 1, col});
        }
        if(col > 0 && tomato[row][col - 1] == 0) {
            tomato[row][col - 1] = 1;
            next.push({row, col - 1});
        }
        if(col < n - 1 && tomato[row][col + 1] == 0) {
            tomato[row][col + 1] = 1;
            next.push({row, col + 1});
        }

        if(current.empty()) {
            date += !next.empty();
            current = next;
            next = queue<pii>();
        }
    }

    if(!CheckTomato(m, n))
        cout << "-1" << endl;
    else
        cout << date << endl;
    return 0;
}