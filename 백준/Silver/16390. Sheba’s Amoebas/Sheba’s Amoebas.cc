#include <iostream>

using namespace std;

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int height, width;
char image[100][100];
bool visit[100][100];

void FloodFill(int row, int col) {
    visit[row][col] = true;
    for(int i = 0; i < 8; i++) {
        if(row + dy[i] < 0 || row + dy[i] >= height || col + dx[i] < 0 || col + dx[i] >= width)
            continue; 

        if(image[row + dy[i]][col + dx[i]] == '#' && !visit[row + dy[i]][col + dx[i]])
            FloodFill(row + dy[i], col + dx[i]);
    }
}

int main() {
    int cell_count = 0;

    cin >> height >> width;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            cin >> image[row][col];
            visit[row][col] = false;
        }
    }
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(image[row][col] == '#' && !visit[row][col]) {
                cell_count++;
                FloodFill(row, col);
            }
        }
    }

    cout << cell_count << endl;
    return 0;
}