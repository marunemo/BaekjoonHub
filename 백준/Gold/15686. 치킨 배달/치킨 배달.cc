#include <iostream>
#include <queue>
#define INF 2500

using namespace std;
using Pos = pair<int, int>;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int n, m;
vector<vector<int>> map;
vector<Pos> house;
vector<Pos> chicken;
vector<vector<int>> chicken_dist;

bool InRange(Pos pos) {
    if(pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= n)
        return false;
    return true;
}

void ChickenDistance(Pos init) {
    queue<Pos> q = queue<Pos>({init});
    vector<vector<bool>> visit = vector<vector<bool>>(n, vector<bool>(n, false));

    while(!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        if(map[row][col] == 1)
            chicken_dist[row][col] = min(chicken_dist[row][col], abs(row - init.first) + abs(col - init.second));

        for(int i = 0; i < 4; i++) {
            if(!InRange({row + dy[i], col + dx[i]}))
                continue;
            
            if(!visit[row + dy[i]][col + dx[i]]) {
                visit[row + dy[i]][col + dx[i]] = true;
                q.push({row + dy[i], col + dx[i]});
            }
        }
    }
}

int MinDistance(int mask, int index, int count) {
    int dist = INF;

    if(count == m) {
        chicken_dist = vector<vector<int>>(n, vector<int>(n, INF));

        for(int i = 0; i < index; i++) {
            if(mask & (1 << i))
                ChickenDistance({chicken[i]});
        }
        
        dist = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++)
                dist += map[row][col] * chicken_dist[row][col];
        }
        return dist;
    }

    if(index == chicken.size())
        return dist;

    return min(MinDistance(mask, index + 1, count), MinDistance(mask | (1 << index), index + 1, count + 1));
}

int main() {
    cin >> n >> m;

    map = vector<vector<int>>(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];

            if(map[i][j] == 1)
                house.push_back({i, j});
            else if(map[i][j] == 2) {
                chicken.push_back({i, j});
                map[i][j] = 0;
            }
        }
    }

    cout << MinDistance(0, 0, 0) << endl;
    return 0;
}