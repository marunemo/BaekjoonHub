#include <iostream>
#include <queue>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int height, width;
int map[8][8];

bool InRange(int y, int x) {
    if(y < 0)
        return false;
    if(y >= height)
        return false;
    if(x < 0)
        return false;
    if(x >= width)
        return false;
    return true;
}

int GetSize() {
    queue<pair<int, int>> q;
    int copy[8][8];
    int size = 0;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            copy[i][j] = map[i][j];

            if(map[i][j] == 2)
                q.push({i, j});
        }
    }
    
    while(!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for(int d = 0; d < 4; d++) {
            if(!InRange(row + dy[d], col + dx[d]))
                continue;
            
            if(copy[row + dy[d]][col + dx[d]] == 0) {
                copy[row + dy[d]][col + dx[d]] = 2;
                q.push({row + dy[d], col + dx[d]});
            }
        }
    }

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(copy[i][j] == 0)
                size++;
        }
    }

    return size;
}

int FindMaxSize(int row, int col, int count) {
    if(count == 3)
        return GetSize();
    if(row == height)
        return 0;
    if(col == width)
        return FindMaxSize(row + 1, 0, count);
    if(map[row][col] != 0)
        return FindMaxSize(row, col + 1, count);

    int max_size = 0;

    map[row][col] = 1;
    max_size = FindMaxSize(row, col + 1, count + 1);
    map[row][col] = 0;
    max_size = max(max_size, FindMaxSize(row, col + 1, count));

    return max_size;
}

int main() {
    cin >> height >> width;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++)
            cin >> map[i][j];
    }

    cout << FindMaxSize(0, 0, 0) << endl;
    return 0;
}