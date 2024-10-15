#include <iostream>
#include <vector>

using namespace std;
using Pos = pair<int, int>;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int height, width;
    vector<vector<char>> map;
    vector<vector<int>> carrot;
    Pos rabbit;
    vector<Pos> doors;
    int carrot_count = -1;

    cin >> height >> width;
    map.resize(height, vector<char>(width));
    carrot.resize(height, vector<int>(width, -1));

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            cin >> map[row][col];
            
            if(map[row][col] == 'R')
                rabbit = {row, col};
            if(map[row][col] == 'O')
                doors.push_back({row, col});
        }
    }

    carrot[rabbit.first][rabbit.second] = 0;
    for(int col = rabbit.second + 1; col < width; col++) {
        for(int row = 0; row < height; row++) {
            if(map[row][col] == '#')
                continue;

            if(row > 0 && carrot[row - 1][col - 1] != -1)
                carrot[row][col] = max(carrot[row][col], carrot[row - 1][col - 1] + (map[row][col] == 'C'));
            if(carrot[row][col - 1] != -1)
                carrot[row][col] = max(carrot[row][col], carrot[row][col - 1] + (map[row][col] == 'C'));
            if(row < height - 1 && carrot[row + 1][col - 1] != -1)
                carrot[row][col] = max(carrot[row][col], carrot[row + 1][col - 1] + (map[row][col] == 'C'));
        }
    }

    for(Pos door: doors)
        carrot_count = max(carrot_count, carrot[door.first][door.second]);
    cout << carrot_count << endl;
    return 0;
}
