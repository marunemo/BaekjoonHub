#include <iostream>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int height, width;
vector<vector<char>> aqua_space;
vector<vector<int>> conn_comp;
vector<int> parent;
queue<Pos> melting;

/**
 * '.' == 물 공간
 * 'X' == 빙판 공간
 * '/' == 다음 녹을 빙판 공간
 */

void DFS(int row, int col, const int &group) {
    conn_comp[row][col] = group;

    for(int i = 0; i < 4; i++) {
        if(row + dy[i] < 0 || row + dy[i] >= height || col + dx[i] < 0 || col + dx[i] >= width) continue;

        if(aqua_space[row + dy[i]][col + dx[i]] == 'X') {
            melting.push({row + dy[i], col + dx[i]});
            aqua_space[row + dy[i]][col + dx[i]] = '/';
            conn_comp[row + dy[i]][col + dx[i]] = group;
        }
        else if(aqua_space[row + dy[i]][col + dx[i]] == '.' && !conn_comp[row + dy[i]][col + dx[i]]) {
            DFS(row + dy[i], col + dx[i], group);
        }
    }
}

int UnionFind(int node) {
    if(parent[node] == node) return node;
    return parent[node] = UnionFind(parent[node]);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    Pos swan[2];
    int swan_count = 0;
    int group_count = 0;
    int size, due;

    cin >> height >> width;
    aqua_space.resize(height, vector<char>(width));
    conn_comp.resize(height, vector<int>(width));
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            cin >> aqua_space[row][col];

            if(aqua_space[row][col] == 'L') {
                swan[swan_count++] = {row, col};
                aqua_space[row][col] = '.';
            }
        }
    }

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(aqua_space[row][col] == '.' && !conn_comp[row][col]) {
                DFS(row, col, ++group_count);
            }
        }
    }
    
    parent.resize(group_count + 1);
    for(int i = 1; i <= group_count; i++) {
        parent[i] = i;
    }
    
    for(due = 0; !melting.empty() && UnionFind(conn_comp[swan[0].first][swan[0].second]) != UnionFind(conn_comp[swan[1].first][swan[1].second]); due++) {    
        size = melting.size();

        for(int i = 0; i < size; i++) {
            auto [row, col] = melting.front();
            melting.pop();

            aqua_space[row][col] = '.';
            for(int i = 0; i < 4; i++) {
                if(row + dy[i] < 0 || row + dy[i] >= height || col + dx[i] < 0 || col + dx[i] >= width) continue;

                if(aqua_space[row + dy[i]][col + dx[i]] == 'X') {
                    melting.push({row + dy[i], col + dx[i]});
                    aqua_space[row + dy[i]][col + dx[i]] = '/';
                    conn_comp[row + dy[i]][col + dx[i]] = conn_comp[row][col];
                }
                else if(aqua_space[row + dy[i]][col + dx[i]] == '.' && UnionFind(conn_comp[row][col]) != UnionFind(conn_comp[row + dy[i]][col + dx[i]])) {
                    if(parent[conn_comp[row][col]] < parent[conn_comp[row + dy[i]][col + dx[i]]]) {
                        parent[parent[conn_comp[row + dy[i]][col + dx[i]]]] = parent[conn_comp[row][col]];
                    }
                    else {
                        parent[parent[conn_comp[row][col]]] = parent[conn_comp[row + dy[i]][col + dx[i]]];
                    }
                }
            }
        }
    }

    cout << due << endl;
    return 0;
}