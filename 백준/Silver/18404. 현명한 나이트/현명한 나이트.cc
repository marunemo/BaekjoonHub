#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};

bool visit[501][501];
queue<pii> pos;

bool InRange(int row, int col, int size) {
    if(row < 1)
        return false;
    if(row > size)
        return false;
    if(col < 1)
        return false;
    if(col > size)
        return false;
    return !visit[row][col];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int size, enemy_count;
    pii knight;
    pii enemy[1000];
    int count[1000] = {0};
    int found = 0;

    cin >> size >> enemy_count;
    cin >> knight.first >> knight.second;
    for(int i = 0; i < enemy_count; i++)
        cin >> enemy[i].first >> enemy[i].second;

    pos.push(knight);
    visit[knight.first][knight.second] = true;

    for(int batch, move = 0; !pos.empty() && found < enemy_count; move++) {
        batch = pos.size();
        while(batch--) {
            auto [row, col] = pos.front();
            pos.pop();

            for(int i = 0; i < enemy_count; i++) {
                if(!count[i] && row == enemy[i].first && col == enemy[i].second)
                    count[i] = move;
            }

            for(int i = 0; i < 8; i++) {
                if(!InRange(row + dy[i], col + dx[i], size))
                    continue;

                visit[row + dy[i]][col + dx[i]] = true;
                pos.push({row + dy[i], col + dx[i]});
            }
        }
    }

    for(int i = 0; i < enemy_count; i++)
        cout << count[i] << ' ';
    cout << endl;
    return 0;
}