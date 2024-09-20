#include <iostream>
#include <queue>
// 125 * 125 * 10
#define INF 156250

using namespace std;
using Pos = pair<int, int>;
using Node = pair<int, Pos>;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

priority_queue<Node, vector<Node>, greater<Node>> pq;
int map[125][125];
int key[125][125];

bool InRange(int row, int col, int size) {
    if(row < 0)
        return false;
    if(row >= size)
        return false;
    if(col < 0)
        return false;
    if(col >= size)
        return false;
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int size;

    cin >> size;
    for(int tc = 1; size; tc++) {
        for(int row = 0; row < size; row++) {
            for(int col = 0; col < size; col++) {
                cin >> map[row][col];
                key[row][col] = INF;
            }
        }

        key[0][0] = map[0][0];
        pq.push({key[0][0], {0, 0}});
        while(!pq.empty()) {
            int weight = pq.top().first;
            auto [row, col] = pq.top().second;
            pq.pop();

            for(int i = 0; i < 4; i++) {
                if(!InRange(row + dy[i], col + dx[i], size))
                    continue;
                
                if(key[row + dy[i]][col + dx[i]] > weight + map[row + dy[i]][col + dx[i]]) {
                    key[row + dy[i]][col + dx[i]] = weight + map[row + dy[i]][col + dx[i]];
                    pq.push({key[row + dy[i]][col + dx[i]], {row + dy[i], col + dx[i]}});
                }
            }
        }

        cout << "Problem " << tc << ": " << key[size - 1][size - 1] << '\n';
        cin >> size;
    }
    return 0;
}