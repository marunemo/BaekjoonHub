#include <iostream>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

bool lamp[10][10];

void CopyLamp(bool src[10][10], bool dest[10][10]) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++)
            dest[i][j] = src[i][j];
    }
}

bool SwitchLamp(int row, int col) {
    lamp[row][col] = !lamp[row][col];
    for(int i = 0; i < 4; i++) {
        if(row + dy[i] >= 0 && row + dy[i] < 10 && col + dx[i] >= 0 && col + dx[i] < 10)
            lamp[row + dy[i]][col + dx[i]] = !lamp[row + dy[i]][col + dx[i]];
    }
    return true;
}

bool CheckLamp() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(lamp[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    bool init[10][10];
    char turn;
    int count;
    int min_count = 1000;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> turn;
            init[i][j] = (turn == 'O');
        }
    }

    for(int mask = 0; mask < (1 << 10); mask++) {
        CopyLamp(init, lamp);

        count = 0;
        for(int index = 0; index < 10; index++) {
            if(mask & (1 << index))
                count += SwitchLamp(0, index);
        }

        for(int row = 1; row < 10; row++) {
            for(int col = 0; col < 10; col++) {
                if(lamp[row - 1][col])
                    count += SwitchLamp(row, col);
            }
        }

        if(CheckLamp())
            min_count = min(count, min_count);
    }

    if(min_count == 1000)
        cout << -1 << endl;
    else
        cout << min_count << endl;
    return 0;
}