#include <iostream>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int main() {
    int height, width;
    vector<vector<bool>> map;
    char obj;
    queue<Pos> Q;
    int size, path;
    bool finish;

    cin >> height >> width;
    map = vector<vector<bool>>(height, vector<bool>(width));
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            cin >> obj;
            map[row][col] = (obj == '1');
        }
    }

    Q.push({0, 0});
    map[0][0] = false;

    path = 0;
    finish = false;
    while(!Q.empty() && !finish) {
        path++;
        size = Q.size();
        for(int i = 0; i < size && !finish; i++) {
            auto[row, col] = Q.front();
            Q.pop();

            if(row == height - 1 && col == width - 1) {
                finish = true;
                break;
            }

            for(int d = 0; d < 4; d++) {
                if(row + dy[d] < 0 || row + dy[d] >= height || col + dx[d] < 0 || col + dx[d] >= width)
                    continue;
                
                if(map[row + dy[d]][col + dx[d]]) {
                    map[row + dy[d]][col + dx[d]] = false;
                    Q.push({row + dy[d], col + dx[d]});
                }
            }
        }
    }

    cout << path << endl;
    return 0;
}