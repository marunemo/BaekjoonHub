#include <iostream>

using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int height, width;
int map[100][100];

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void VerticalFlip() {
    for(int col = 0; col < width; col++) {
        for(int row = 0; row < height / 2; row++)
            Swap(map[row][col], map[height - row - 1][col]);
    }
}

void HorizontalFlip() {
    for(int row = 0; row < height; row++)
        for(int col = 0; col < width / 2; col++) {
            Swap(map[row][col], map[row][width - col - 1]);
    }
}

void Transpose() {
    int range = max(height, width);

    for(int row = 0; row < range; row++) {
        for(int col = row + 1; col < range; col++)
            Swap(map[row][col], map[col][row]);
    }
    Swap(height, width);
}

void RightRotate() {
    VerticalFlip();
    Transpose();
}

void LeftRotate() {
    HorizontalFlip();
    Transpose();
}

void RightRotateSection() {
    int x_sec[4] = {0, width / 2, width / 2, 0};
    int y_sec[4] = {0, 0, height / 2, height / 2};
    int x_size = width / 2;
    int y_size = height / 2;
    int result[100][100];

    for(int i = 0; i < 4; i++) {
        for(int dy = 0; dy < y_size; dy++) {
            for(int dx = 0; dx < x_size; dx++)
                result[y_sec[(i + 1) % 4] + dy][x_sec[(i + 1) % 4] + dx] = map[y_sec[i] + dy][x_sec[i] + dx];
        }
    }

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            map[row][col] = result[row][col];
    }
}

void LeftRotateSection() {
    int x_sec[4] = {0, 0, width / 2, width / 2};
    int y_sec[4] = {0, height / 2, height / 2, 0};
    int x_size = width / 2;
    int y_size = height / 2;
    int result[100][100];

    for(int i = 0; i < 4; i++) {
        for(int dy = 0; dy < y_size; dy++) {
            for(int dx = 0; dx < x_size; dx++)
                result[y_sec[(i + 1) % 4] + dy][x_sec[(i + 1) % 4] + dx] = map[y_sec[i] + dy][x_sec[i] + dx];
        }
    }

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            map[row][col] = result[row][col];
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int query, cmd;

    cin >> height >> width >> query;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            cin >> map[row][col];
    }

    while(query--) {
        cin >> cmd;
        switch(cmd) {
            case 1:
                VerticalFlip();
                break;
            case 2:
                HorizontalFlip();
                break;
            case 3:
                RightRotate();
                break;
            case 4:
                LeftRotate();
                break;
            case 5:
                RightRotateSection();
                break;
            case 6:
                LeftRotateSection();
                break;
        }
    }

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            cout << map[row][col] << ' ';
        cout << '\n';
    }
    return 0;
}