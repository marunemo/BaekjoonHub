#include <iostream>
#include <queue>
#define INF 2501

using namespace std;

struct Node {
    int change, row, col;
};

struct Compare {
    bool operator()(Node a, Node b) {
        return a.change > b.change;
    }
};

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int map_size;
vector<vector<bool>> map;
priority_queue<Node, vector<Node>, Compare> heap;
vector<vector<int>> key_change;

bool InRange(int row, int col) {
    return row >= 0 && row < map_size && col >= 0 && col < map_size;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    char mark;
    Node node, next;

    cin >> map_size;

    map.resize(map_size, vector<bool>(map_size));
    key_change.resize(map_size, vector<int>(map_size, INF));

    for(int row = 0; row < map_size; row++) {
        for(int col = 0; col < map_size; col++) {
            cin >> mark;
            map[row][col] = mark == '1';
        }
    }

    node.change = node.row = node.col = 0;
    key_change[0][0] = 0;
    heap.push(node);

    while(!heap.empty()) {
        node = heap.top();
        heap.pop();

        if(key_change[node.row][node.col] < node.change)
            continue;

        for(int i = 0; i < 4; i++) {
            next.row = node.row + dy[i];
            next.col = node.col + dx[i];

            if(!InRange(next.row, next.col))
                continue;
            next.change = node.change + !map[next.row][next.col];
            
            if(key_change[next.row][next.col] > next.change) {
                key_change[next.row][next.col] = next.change;
                heap.push(next);
            }
        }
    }

    cout << key_change[map_size - 1][map_size - 1] << endl;
    return 0;
}