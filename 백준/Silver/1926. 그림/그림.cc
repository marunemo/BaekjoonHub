#include <iostream>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int height, width;
bool paint[500][500];

int ConnectedComponent(int row, int col) {
    int count = 1;

    paint[row][col] = false;
    for(int i = 0; i < 4; i++) {
        if(row + dy[i] < 0 || row + dy[i] >= height || col + dx[i] < 0 || col + dx[i] >= width)
            continue;
        
        if(paint[row + dy[i]][col + dx[i]])
            count += ConnectedComponent(row + dy[i], col + dx[i]);
    }

    return count;
}

int main() {
    int pixel;
    int paint_count = 0;
    int max_area = 0;

    cin >> height >> width;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            cin >> pixel;
            paint[row][col] = (pixel == 1);
        }
    }

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(paint[row][col]) {
                paint_count++;
                max_area = max(max_area, ConnectedComponent(row, col));
            }
        }
    }

    cout << paint_count << '\n' << max_area << endl;
    return 0;
}