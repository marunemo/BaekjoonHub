#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int height, width, rotate;
int arr[300][300];
bool check[300][300];
vector<pii> rotateList[300];
int rotateIndex = 0;
int result[300][300];

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

void RotateArray(int rotate) {
    for(int i = 0; i < rotateIndex; i++) {
        int size = rotateList[i].size();
        for(int j = 0; j < size; j++) {
            pii curr = rotateList[i][j];
            pii next = rotateList[i][(rotate + j) % size];
            result[next.first][next.second] = arr[curr.first][curr.second];
        }
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
        row++;
        rotateIndex++;
    }

    RotateArray(rotate);
    for(row = 0; row < height; row++) {
        for(col = 0; col < width; col++)
            cout << result[row][col] << ' ';
        cout << '\n';
    }
    return 0;
}