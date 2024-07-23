#include <iostream>
#define INF 1000000

using namespace std;
using Pos = pair<int, int>;

const char dir[4] = {'W', 'S', 'N', 'E'};
const char mark[4] = {'<', 'v', '^', '>'};
const int x_dir[4] = {-1, 0, 0, 1};
const int y_dir[4] = {0, 1, -1, 0};

char map[100][100];

int Drift(Pos curr) {
    Pos next = curr;

    if(map[curr.first][curr.second] == '.')
        return INF;
    if(map[curr.first][curr.second] == 'x')
        return 0;

    for(int i = 0; i < 4; i++) {
        if(map[curr.first][curr.second] == mark[i]) {
            next.first += y_dir[i];
            next.second += x_dir[i];
        }
    }
    return Drift(next) + 1;
}

int main() {
    int height, width;
    Pos pos;
    int min_dist, dist;
    char result;

    cin >> height >> width;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            cin >> map[row][col];
            if(map[row][col] == 'o') {
                pos = {row, col};
                map[row][col] = '.';
            }
        }
    }

    min_dist = INF - 1;
    result = 'X';
    for(int i = 0; i < 4; i++) {
        dist = Drift({pos.first + y_dir[i], pos.second + x_dir[i]});
        if(dist <= min_dist) {
            min_dist = dist;
            result = dir[i];
        }
    }
    
    if(result == 'X')
        cout << ":(" << endl;
    else
        cout << ":)\n" << result << endl;
    return 0;
}