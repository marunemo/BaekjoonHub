#include <iostream>
#include <queue>

using namespace std;

int main() {
    int size;
    int map[3][3];
    bool visit[3][3] = {0};
    queue<pair<int, int>> q;
    bool flag = false;

    cin >> size;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++)
            cin >> map[i][j];
    }

    visit[0][0] = true;
    q.push({0, 0});

    while(!q.empty() && !flag) {
        auto [row, col] = q.front();
        q.pop();

        if(row == size - 1 && col == size - 1)
            flag = true;
        if(row + map[row][col] < size && !visit[row + map[row][col]][col]) {
            visit[row + map[row][col]][col] = true;
            q.push({row + map[row][col], col});
        }
        if(col + map[row][col] < size && !visit[row][col + map[row][col]]) {
            visit[row][col + map[row][col]] = true;
            q.push({row, col + map[row][col]});
        }
    }

    if(flag)
        cout << "HaruHaru" << endl;
    else
        cout << "Hing" << endl;
    return 0;
}