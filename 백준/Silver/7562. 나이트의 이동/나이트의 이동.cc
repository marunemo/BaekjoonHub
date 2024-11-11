#include <iostream>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

const int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc, size, iter, move;
    Pos pos, end;
    queue<Pos> Q;
    vector<vector<bool>> board;
    bool finding;

    cin >> tc;
    while(tc--) {
        cin >> size >> pos.first >> pos.second >> end.first >> end.second;

        board = vector<vector<bool>>(size, vector<bool>(size, false));
        Q = queue<Pos>({pos});
        board[pos.first][pos.second] = true;

        finding = true;
        for(move = 0; !Q.empty() && finding; move += finding) {
            iter = Q.size();

            for(int i = 0; i < iter; i++) {
                pos = Q.front();
                Q.pop();

                if(pos.first == end.first && pos.second == end.second) {
                    finding = false;
                    break;
                }

                for(int i = 0; i < 8; i++) {
                    if(pos.first + dy[i] < 0 || pos.first + dy[i] >= size || pos.second + dx[i] < 0 || pos.second + dx[i] >= size)
                        continue;
                    if(board[pos.first + dy[i]][pos.second + dx[i]])
                        continue;

                    Q.push({pos.first + dy[i], pos.second + dx[i]});
                    board[pos.first + dy[i]][pos.second + dx[i]] = true;
                }
            }
        }

        cout << move << '\n';
    }
    return 0;
}