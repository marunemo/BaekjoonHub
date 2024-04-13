#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
using Pos = pair<int, int>;
using Key = unordered_map<char, bool>;
using Visit = vector<vector<bool>>;

char map[100][100];

vector<Pos> FindBackdoor(int height, int width, Key key) {
    vector<Pos> backdoor;

    for(int row = 0; row < height; row++) {
        if(map[row][0] != '*')
            backdoor.push_back({row, 0});
        if(map[row][width - 1] != '*')
            backdoor.push_back({row, width - 1});
    }

    for(int col = 0; col < width; col++) {
        if(map[0][col] != '*')
            backdoor.push_back({0, col});
        if(map[height - 1][col] != '*')
            backdoor.push_back({height - 1, col});
    }

    return backdoor;
}

int FloodFill(int height, int width, Key key) {
    bool not_found = false;
    Visit visit;
    vector<Pos> backdoor;
    queue<Pos> q;
    int count = 0;

    while(!not_found) {
        not_found = true;
        visit = Visit(height, vector<bool>(width, false));
        backdoor = FindBackdoor(height, width, key);

        for(auto door: backdoor) {
            q.push(door);
            visit[door.first][door.second] = true;
        }
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if(map[row][col] == '$') {
                map[row][col] = '.';
                count++;
            }
            else if(map[row][col] >= 'a' && map[row][col] <= 'z') {
                key['A' + (map[row][col] - 'a')] = true;
                map[row][col] = '.';
                not_found = false;
            }
            else if(map[row][col] >= 'A' && map[row][col] <= 'Z') {
                if(key[map[row][col]])
                    map[row][col] = '.';
                else
                    continue;
            }

            if(row > 0 && !visit[row - 1][col] && map[row - 1][col] != '*') {
                visit[row - 1][col] = true;
                q.push({row - 1, col});
            }
            if(row < height - 1 && !visit[row + 1][col] && map[row + 1][col] != '*') {
                visit[row + 1][col] = true;
                q.push({row + 1, col});
            }
            if(col > 0 && !visit[row][col - 1] && map[row][col - 1] != '*') {
                visit[row][col - 1] = true;
                q.push({row, col - 1});
            }
            if(col < width - 1 && !visit[row][col + 1] && map[row][col + 1] != '*') {
                visit[row][col + 1] = true;
                q.push({row, col + 1});
            }
        }
    }
    return count;
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int test_case;
    int height, width;
    string keys;
    Key key;

    cin >> test_case;
    while(test_case--) {
        cin >> height >> width;
        for(int row = 0; row < height; row++) {
            for(int col = 0; col < width; col++)
                cin >> map[row][col];
        }
        
        cin >> keys;
        key.clear();
        for(auto k: keys)
            key['A' + (k - 'a')] = true;
        cout << FloodFill(height, width, key) << '\n';
    }
    return 0;
}