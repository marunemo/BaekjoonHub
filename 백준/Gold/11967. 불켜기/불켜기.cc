#include <iostream>
#include <queue>

using namespace std;
using Pos = pair<int, int>;
using Mask1 = vector<bool>;
using Mask2 = vector<Mask1>;

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    int x, y, a, b;
    vector<vector<vector<Pos>>> adj_matrix;
    Mask2 switch_on;
    Mask2 light_on;
    Mask2 visit;
    queue<Pos> q;
    int count = 0;
    bool turn_on = true;

    cin >> n >> m;
    adj_matrix = vector<vector<vector<Pos>>>(n + 1, vector<vector<Pos>>(n + 1, vector<Pos>()));
    while(m--) {
        cin >> x >> y >> a >> b;
        adj_matrix[x][y].push_back({a, b});
    }

    light_on = Mask2(n + 1, Mask1(n + 1, false));
    switch_on = Mask2(n + 1, Mask1(n + 1, false));

    light_on[1][1] = true;
    switch_on[1][1] = true;
    for(auto light: adj_matrix[1][1])
        light_on[light.first][light.second] = true;

    while(turn_on) {
        turn_on = false;
        visit = Mask2(n + 1, Mask1(n + 1, false));
        visit[1][1] = true;

        q.push({1, 1});
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if(!switch_on[row][col]) {
                switch_on[row][col] = true;
                for(auto light: adj_matrix[row][col]) {
                    if(!light_on[light.first][light.second])
                        light_on[light.first][light.second] = true;
                }
                turn_on = true;
            }

            if(row > 1 && light_on[row - 1][col] && !visit[row - 1][col]) {
                visit[row - 1][col] = true;
                q.push({row - 1, col});
            }
            if(row < n && light_on[row + 1][col] && !visit[row + 1][col]) {
                visit[row + 1][col] = true;
                q.push({row + 1, col});
            }
            if(col > 1 && light_on[row][col - 1] && !visit[row][col - 1]) {
                visit[row][col - 1] = true;
                q.push({row, col - 1});
            }
            if(col < n && light_on[row][col + 1] && !visit[row][col + 1]) {
                visit[row][col + 1] = true;
                q.push({row, col + 1});
            }
        }
    }

    for(int row = 1; row <= n; row++) {
        for(int col = 1; col <= n; col++)
            count += light_on[row][col];
    }

    cout << count << endl;
    return 0;
}