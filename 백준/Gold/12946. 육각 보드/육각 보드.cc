#include <iostream>

using namespace std;

int map_size;
char map[50][50];
int color[50][50] = {0};

int dir[6][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1}};

int DFS(int row, int col, int clr) {
    color[row][col] = clr;

    int count = 1;
    for(int i = 0; i < 6 && count < 3; i++) {
        if(row + dir[i][0] >= 0 && row + dir[i][0] < map_size && col + dir[i][1] >= 0 && col + dir[i][1] < map_size) {
            if(map[row + dir[i][0]][col + dir[i][1]] == 'X') {
                if(!color[row + dir[i][0]][col + dir[i][1]])
                    count = max(2, DFS(row + dir[i][0], col + dir[i][1], -clr));
                else if(color[row + dir[i][0]][col + dir[i][1]] == clr)
                    return 3;
            }
        }
    }
    return count;
}

int main() {
    int count = 0;

    cin >> map_size;
    for(int row = 0; row < map_size; row++) {
        for(int col = 0; col < map_size; col++)
            cin >> map[row][col];
    }

    for(int row = 0; row < map_size && count < 3; row++) {
        for(int col = 0; col < map_size && count < 3; col++) {
            if(map[row][col] == 'X' && !color[row][col])
                count = max(count, DFS(row, col, 1));
        }
    }

    cout << count << endl;
    return 0;
}