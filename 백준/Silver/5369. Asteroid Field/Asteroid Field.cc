#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int tc, map_size;
vector<vector<char>> map;
queue<pii> q;

bool InRange(int row, int col) {
    if(row < 0)
        return false;
    if(row >= map_size)
        return false;
    if(col < 0)
        return false;
    if(col >= map_size)
        return false;
    if(map[row][col] == '*')
        return false;
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    pii pos;
    int min_count, count;
    int batch;

    cin >> tc;
    while(tc--) {
        cin >> map_size;

        map = vector<vector<char>>(map_size, vector<char>(map_size));
        for(int row = 0; row < map_size; row++) {
            for(int col = 0; col < map_size; col++) {
                cin >> map[row][col];
                if(map[row][col] == 's')
                    pos = {row, col};
            }
        }

        min_count = map_size * map_size;
        q.push(pos);
        map[pos.first][pos.second] = '*';
        for(count = 0; !q.empty(); count++) {
            batch = q.size();
            for(int i = 0; i < batch; i++) {
                pos = q.front();
                q.pop();

                if(map[pos.first][pos.second] == 'd')
                    min_count = min(count, min_count);
                
                for(int i = 0; i < 4; i++) {
                    if(InRange(pos.first + dy[i], pos.second + dx[i])) {
                        q.push({pos.first + dy[i], pos.second + dx[i]});
                        if(map[pos.first + dy[i]][pos.second + dx[i]] != 'd')
                            map[pos.first + dy[i]][pos.second + dx[i]] = '*';
                    }
                }
            }

            if(min_count != map_size * map_size)
                break;
        }

        if(min_count == map_size * map_size)
            cout << -1 << '\n';
        else
            cout << min_count << '\n';
    }
    return 0;
}