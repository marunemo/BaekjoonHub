#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int height, width, rotate;
int arr[300][300];
bool check[300][300];
vector<pii> rotateList[300];
int rotateIndex = 0;

bool InRange(int row, int col) {
    if(row < 0)
        return false;
    if(row >= height)
        return false;
    if(col < 0)
        return false;
    if(col >= width)
        return false;
    return !check[row][col];
}

void RotateArray() {
    for(int i = 0; i < rotateIndex; i++) {
        int tmp = arr[rotateList[i][0].first][rotateList[i][0].second];
        int size = rotateList[i].size();
        for(int j = 1; j < size; j++) {
            pii pos1 = rotateList[i][j - 1];
            pii pos2 = rotateList[i][j];
            arr[pos1.first][pos1.second] = arr[pos2.first][pos2.second];
        }
        arr[rotateList[i][size - 1].first][rotateList[i][size - 1].second] = tmp;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int row, col;

    cin >> height >> width >> rotate;
    for(row = 0; row < height; row++) {
        for(col = 0; col < width; col++) {
            cin >> arr[row][col];
            check[row][col] = false;
        }
    }

    row = col = 0;
    while(InRange(row, col)) {
        check[row][col] = true;
        rotateList[rotateIndex].push_back({row, col});
        for(int i = 0; i < 4; i++) {
            while(InRange(row + dy[i], col + dx[i])) {
                row = row + dy[i];
                col = col + dx[i];
                check[row][col] = true;
                rotateList[rotateIndex].push_back({row, col});
            }
        }
        col++;
        rotateIndex++;
    }

    while(rotate--)
        RotateArray();

    for(row = 0; row < height; row++) {
        for(col = 0; col < width; col++)
            cout << arr[row][col] << ' ';
        cout << '\n';
    }
    return 0;
}