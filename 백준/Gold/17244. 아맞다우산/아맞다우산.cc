#include <iostream>
#include <queue>
#define INF 100000

using namespace std;
using Pos = pair<int, int>;

int width, height;
char map[50][50];

// [5][~]: from start, [~][5]: to end
int adj_matrix[6][6];

void MakeAdjMatrix(int index, Pos item_pos) {
    queue<Pos> current_pos;
    queue<Pos> next_pos;
    int depth = 0;

    bool visit[50][50];
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            visit[row][col] = false;
    }

    current_pos.push(item_pos);
    while(!current_pos.empty()) {
        item_pos = current_pos.front();
        current_pos.pop();

        if(map[item_pos.first][item_pos.second] >= '0' && map[item_pos.first][item_pos.second] <= '4')
            adj_matrix[index][map[item_pos.first][item_pos.second] - '0'] = depth;
        else if(map[item_pos.first][item_pos.second] == 'E')
            adj_matrix[index][5] = depth;

        if(item_pos.first > 0 && map[item_pos.first - 1][item_pos.second] != '#' && !visit[item_pos.first - 1][item_pos.second]) {
            next_pos.push({item_pos.first - 1, item_pos.second});
            visit[item_pos.first - 1][item_pos.second] = true;
        }
        if(item_pos.first < height - 1 && map[item_pos.first + 1][item_pos.second] != '#' && !visit[item_pos.first + 1][item_pos.second]) {
            next_pos.push({item_pos.first + 1, item_pos.second});
            visit[item_pos.first + 1][item_pos.second] = true;
        }
        if(item_pos.second > 0 && map[item_pos.first][item_pos.second - 1] != '#' && !visit[item_pos.first][item_pos.second - 1]) {
            next_pos.push({item_pos.first, item_pos.second - 1});
            visit[item_pos.first][item_pos.second - 1] = true;
        }
        if(item_pos.second < width - 1 && map[item_pos.first][item_pos.second + 1] != '#' && !visit[item_pos.first][item_pos.second + 1]) {
            next_pos.push({item_pos.first, item_pos.second + 1});
            visit[item_pos.first][item_pos.second + 1] = true;
        }

        if(current_pos.empty()) {
            current_pos = next_pos;
            next_pos = queue<Pos>();
            depth++;
        }
    }    
}

int PathFinding(int item_count, int mask, int index) {
    if(mask == (1 << item_count) - 1)
        return adj_matrix[index][5];

    int min_cost = INF;
    for(int item = 0; item < item_count; item++) {
        if(!(mask & (1 << item)))
            min_cost = min(min_cost, adj_matrix[index][item] + PathFinding(item_count, (mask | (1 << item)), item));
    }

    return min_cost;
}

int main() {
    char entity;

    Pos start;
    Pos item_pos[5];
    int item_count = 0;

    cin >> width >> height;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            cin >> entity;
            map[row][col] = entity;

            if(entity == 'S')
                start = {row, col};
            else if(entity == 'X') {
                item_pos[item_count] = {row, col};
                map[row][col] = '0' + item_count;
                item_count++;
            }
        }
    }

    for(int item = 0; item < item_count; item++)
        MakeAdjMatrix(item, item_pos[item]);
    MakeAdjMatrix(5, start);

    cout << PathFinding(item_count, 0, 5) << endl;
    return 0;
}