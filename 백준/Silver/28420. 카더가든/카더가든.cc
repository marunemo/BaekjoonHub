#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mask[3];
vector<vector<int>> map;

int main() {
    int height, width;
    int car_width, car_length, camp_length;
    int cost, min_cost = 0;

    cin >> height >> width;
    cin >> car_width >> car_length >> camp_length;

    map = vector<vector<int>>(height, vector<int>(width));
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cin >> map[i][j];
            min_cost += map[i][j];
        }
    }

    // fig 1.
    mask[0] = vector<vector<int>>(car_width, vector<int>(car_length + camp_length, 1));

    // fig 2.
    mask[1] = vector<vector<int>>(car_width + car_length, vector<int>(car_width + camp_length, 0));
    for(int i = 0; i < car_width; i++) {
        for(int j = 0; j < camp_length; j++)
            mask[1][i][j] = 1;
    }
    for(int i = 0; i < car_width; i++) {
        for(int j = 0; j < car_length; j++)
            mask[1][car_width + j][camp_length + i] = 1;
    }

    // fig 3.
    mask[2] = vector<vector<int>>(car_width + camp_length, vector<int>(car_length + car_width, 0));
    for(int i = 0; i < car_width; i++) {
        for(int j = 0; j < car_length; j++)
            mask[2][i][j] = 1;
    }
    for(int i = 0; i < car_width; i++) {
        for(int j = 0; j < camp_length; j++)
            mask[2][car_width + j][car_length + i] = 1;
    }

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            for(int index = 0; index < 3; index++) {
                if(row + mask[index].size() > height || col + mask[index][0].size() > width)
                    continue;
                
                cost = 0;
                for(int i = 0; i < mask[index].size(); i++) {
                    for(int j = 0; j < mask[index][i].size(); j++)
                        cost += mask[index][i][j] * map[row + i][col + j];
                }

                min_cost = min(cost, min_cost);
            }
        }
    }

    cout << min_cost << endl;
    return 0;
}