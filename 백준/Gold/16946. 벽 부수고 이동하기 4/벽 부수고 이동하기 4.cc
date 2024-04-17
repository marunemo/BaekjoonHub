#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int height, width;
bool wall[1000][1000];

int group[1000][1000] = {0};
int group_index = 0;
unordered_map<int, int> move_count;

void FloodFill(int row, int col) {
    if(group[row][col])
        return;

    queue<pair<int, int>> move;
    int count = 1;
    
    // 시작 위치 인큐
    move.push({row, col});
    group[row][col] = ++group_index;
    
    // BFS로 이동 가능 노드 탐색 및 개수 확인
    while(!move.empty()) {
        row = move.front().first;
        col = move.front().second;
        move.pop();

        for(int i = 0; i < 4; i++) {
            if(row + dx[i] < 0 || row + dx[i] >= height || col + dy[i] < 0 || col + dy[i] >= width)
                continue;
            
            if(!group[row + dx[i]][col + dy[i]] && !wall[row + dx[i]][col + dy[i]]) {
                group[row + dx[i]][col + dy[i]] = group_index;
                move.push({row + dx[i], col + dy[i]});
                count++;
            }
        }
    }

    move_count[group_index] = count;
}

int CountMovable(int row, int col) {
    // 현재 벽을 포함한 개수
    int count = 1;
    unordered_map<int, bool> visit;

    // 인접한 이동 가능 횟수 저장
    for(int i = 0; i < 4; i++) {
        if(row + dx[i] < 0 || row + dx[i] >= height || col + dy[i] < 0 || col + dy[i] >= width)
            continue;
        
        if(wall[row + dx[i]][col + dy[i]])
            continue;

        FloodFill(row + dx[i], col + dy[i]);

        if(!visit[group[row + dx[i]][col + dy[i]]]) {
            visit[group[row + dx[i]][col + dy[i]]] = true;
            count += move_count[group[row + dx[i]][col + dy[i]]];
        }
    }

    // 칸의 개수를 10으로 나눈 나머지 출력
    return count % 10;
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    char map;
    
    cin >> height >> width;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            cin >> map;
            wall[row][col] = (map == '1');
        }
    }


    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(!wall[row][col])
                cout << '0';
            else
                cout << CountMovable(row, col);
        }
        cout << '\n';
    }
    return 0;
}