#include <iostream>
#define VISITED 1
#define GOTO_SAFE 2

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int visit[1000][1000] = {0};
int map[1000][1000] = {0};

bool DFS(int row, int col) {
    if(visit[row][col] == VISITED)
        return true;
    
    if(visit[row][col] == GOTO_SAFE)
        return false;

    visit[row][col] = VISITED;
    bool flag = DFS(row + dx[map[row][col]], col + dy[map[row][col]]);

    visit[row][col] = GOTO_SAFE;
    return flag;
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int height, width;
    char dir;
    int safe_count = 0;

    cin >> height >> width;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            cin >> dir;
            if(dir == 'U')
                map[row][col] = 0;
            else if(dir == 'D')
                map[row][col] = 1;
            else if(dir == 'L')
                map[row][col] = 2;
            else if(dir == 'R')
                map[row][col] = 3;
        }
    }

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(!visit[row][col])
                safe_count += DFS(row, col);
        }
    }

    cout << safe_count << endl;
    return 0;
}