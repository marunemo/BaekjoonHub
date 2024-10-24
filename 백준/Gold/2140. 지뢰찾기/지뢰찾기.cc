#include <iostream>

using namespace std;

const int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    int n;
    char map[100][100];
    int count = 0;
    bool flag;

    cin >> n;
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++)
            cin >> map[row][col];
    }

    for(int row = 1; row < n - 1; row++) {
        for(int col = 1; col < n - 1; col++) {
            flag = true;
            for(int i = 0; i < 8 && flag; i++)
                flag &= map[row + dy[i]][col + dx[i]] != '0';
            
            if(!flag)
                continue;
            
            count++;
            for(int i = 0; i < 8 && flag; i++) {
                if(map[row + dy[i]][col + dx[i]] >= '1' && map[row + dy[i]][col + dx[i]] <= '3')
                    map[row + dy[i]][col + dx[i]]--;
            }
        }
    }

    cout << count << endl;
    return 0;
}