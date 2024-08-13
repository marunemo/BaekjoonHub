#include <iostream>

using namespace std;

char letter[100][100];

bool InRange(int row, int col, int height, int width) {
    if(row < 0)
        return false;
    if(row >= height)
        return false;
    if(col < 0)
        return false;
    if(col >= width)
        return false;
    return true;
}

void Swap(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

void PullUp(int height, int width) {
    int next_r, next_c;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(letter[row][col] == '.')
                continue;

            next_r = row - 1;
            next_c = col;

            while(InRange(next_r, next_c, height, width) && letter[next_r][next_c] == '.') {
                Swap(letter[next_r][next_c], letter[next_r + 1][next_c]);
                next_r--;
            }
        }
    }
}

void PullDown(int height, int width) {
    int next_r, next_c;
    for(int row = height - 1; row >= 0; row--) {
        for(int col = 0; col < width; col++) {
            if(letter[row][col] == '.')
                continue;

            next_r = row + 1;
            next_c = col;

            while(InRange(next_r, next_c, height, width) && letter[next_r][next_c] == '.') {
                Swap(letter[next_r][next_c], letter[next_r - 1][next_c]);
                next_r++;
            }
        }
    }
}

void PullLeft(int height, int width) {
    int next_r, next_c;
    for(int col = 0; col < width; col++) {
        for(int row = 0; row < height; row++) {
            if(letter[row][col] == '.')
                continue;

            next_r = row;
            next_c = col - 1;

            while(InRange(next_r, next_c, height, width) && letter[next_r][next_c] == '.') {
                Swap(letter[next_r][next_c], letter[next_r][next_c + 1]);
                next_c--;
            }
        }
    }
}

void PullRight(int height, int width) {
    int next_r, next_c;
    for(int col = width - 1; col >= 0; col--) {
        for(int row = 0; row < height; row++) {
            if(letter[row][col] == '.')
                continue;

            next_r = row;
            next_c = col + 1;

            while(InRange(next_r, next_c, height, width) && letter[next_r][next_c] == '.') {
                Swap(letter[next_r][next_c], letter[next_r][next_c - 1]);
                next_c++;
            }
        }
    }
}

int main() {
    int height, width, phase;
    char dir[100];

    cin >> height >> width >> phase;
    for(int i = 0; i < phase; i++)
        cin >> dir[i];
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            cin >> letter[row][col];
    }

    for(int i = 0; i < phase; i++) {
        if(dir[i] == 'U')
            PullUp(height, width);
        else if(dir[i] == 'D')
            PullDown(height, width);
        else if(dir[i] == 'L')
            PullLeft(height, width);
        else if(dir[i] == 'R')
            PullRight(height, width);
    }

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            cout << letter[row][col];
        cout << '\n';
    }
    return 0;
}