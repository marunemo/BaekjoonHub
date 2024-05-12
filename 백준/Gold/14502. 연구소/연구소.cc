#include <iostream>
#include <queue>

using namespace std;

int Simulate(vector<vector<int>> map) {
    int width = map[0].size();
    int height = map.size();
    int size = 0;

    queue<pair<int, int>> q;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(map[row][col] == 2)
                q.push({row, col});
        }
    }

    while(!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        if(row > 0 && map[row - 1][col] == 0) {
            map[row - 1][col] = 2;
            q.push({row - 1, col});
        }
        if(row < height - 1 && map[row + 1][col] == 0) {
            map[row + 1][col] = 2;
            q.push({row + 1, col});
        }
        if(col > 0 && map[row][col - 1] == 0) {
            map[row][col - 1] = 2;
            q.push({row, col - 1});
        }
        if(col < width - 1 && map[row][col + 1] == 0) {
            map[row][col + 1] = 2;
            q.push({row, col + 1});
        }
    }

    for(int r = 0; r < height; r++) {
        for(int c = 0; c < width; c++) {
            if(map[r][c] != 0)
                continue;
            
            map[r][c] = 3;
            q.push({r, c});
            size++;
            while(!q.empty()) {
                auto [row, col] = q.front();
                q.pop();

                if(row > 0 && map[row - 1][col] == 0) {
                    map[row - 1][col] = 3;
                    q.push({row - 1, col});
                    size++;
                }
                if(row < height - 1 && map[row + 1][col] == 0) {
                    map[row + 1][col] = 3;
                    q.push({row + 1, col});
                    size++;
                }
                if(col > 0 && map[row][col - 1] == 0) {
                    map[row][col - 1] = 3;
                    q.push({row, col - 1});
                    size++;
                }
                if(col < width - 1 && map[row][col + 1] == 0) {
                    map[row][col + 1] = 3;
                    q.push({row, col + 1});
                    size++;
                }
            }
        }
    }

    return size;
}

int DFS(vector<vector<int>> &map, int row, int col, int wall) {
    if(wall == 3)
        return Simulate(map);
    if(row == map.size())
        return 0;
    if(col == map[0].size())
        return DFS(map, row + 1, 0, wall);
    if(map[row][col] != 0)
        return DFS(map, row, col + 1, wall);
    
    map[row][col] = 1;
    int set = DFS(map, row, col + 1, wall + 1);
    map[row][col] = 0;
    int unset = DFS(map, row, col + 1, wall);

    return max(set, unset);
}

int main() {
    int width, height;
    vector<vector<int>> map;

    cin >> height >> width;
    map = vector<vector<int>>(height, vector<int>(width));

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            cin >> map[row][col];
    }

    cout << DFS(map, 0, 0, 0) << endl;
    return 0;
}