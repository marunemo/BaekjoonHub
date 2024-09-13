#include <iostream>
#include <algorithm>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int map_size;
bool map[25][25];
int cc[25][25];
int cc_count;
int house[625];

bool InRange(int row, int col) {
    if(row < 0)
        return false;
    if(row >= map_size)
        return false;
    if(col < 0)
        return false;
    if(col >= map_size)
        return false;
    return map[row][col] && !cc[row][col];
}

int ConnectedComponent(int row, int col) {
    int count = 1;
    
    cc[row][col] = cc_count;
    for(int i = 0; i < 4; i++) {
        if(InRange(row + dy[i], col + dx[i]))
            count += ConnectedComponent(row + dy[i], col + dx[i]);
    }

    return count;
}

int main() {
    char data;

    cin >> map_size;
    for(int row = 0; row < map_size; row++) {
        for(int col = 0; col < map_size; col++) {
            cin >> data;
            map[row][col] = data == '1';
        }
    }

    for(int row = 0; row < map_size; row++) {
        for(int col = 0; col < map_size; col++) {
            if(map[row][col] && !cc[row][col]) {
                cc_count++;
                house[cc_count] = ConnectedComponent(row, col);
            }
        }
    }
    sort(house + 1, house + 1 + cc_count);

    cout << cc_count << '\n';
    for(int i = 1; i <= cc_count; i++)
        cout << house[i] << '\n';
    return 0;
}