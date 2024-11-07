#include <iostream>
#include <queue>
#define NONE 0
#define APPLE 1
#define SNAKE 2

using namespace std;
using Pos = pair<int, int>;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int board_size;
int apple_count;
int board[101][101];
Pos apple[100];
deque<Pos> snake;
int turn_count;
int turn_time;
char turn;
int dir;
int total_time = 0;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> board_size >> apple_count;
    for(int i = 0; i < apple_count; i++) {
        cin >> apple[i].first >> apple[i].second;
        board[apple[i].first][apple[i].second] = APPLE;
    }
    snake.push_front({1, 1});
    board[1][1] = SNAKE;
    dir = 0;

    cin >> turn_count;

    cin >> turn_time >> turn;
    turn_count--;
    for(total_time = 1; ; total_time++) {
        auto [row, col] = snake.front();
        // for(int i = 1; i <= board_size; i++) {
        //     for(int j = 1; j <= board_size; j++) {
        //         switch(board[i][j]) {
        //             case NONE:
        //                 cout << ' ';
        //                 break;
        //             case APPLE:
        //                 cout << '*';
        //                 break;
        //             case SNAKE:
        //                 cout << 'O';
        //         }
        //     }
        //     cout << '\n';
        // }
        // cout << "=============================\n";
        row += dy[dir];
        col += dx[dir];

        if(row < 1 || row > board_size || col < 1 || col > board_size)
            break;
        if(board[row][col] == SNAKE)
            break;

        if(board[row][col] != APPLE) {
            board[snake.back().first][snake.back().second] = NONE;
            snake.pop_back();
        }

        snake.push_front({row, col});
        board[row][col] = SNAKE;

        if(turn_time == total_time) {
            if(turn == 'L')
                dir = (dir - 1 + 4) % 4;
            if(turn == 'D')
                dir = (dir + 1) % 4;
            if(turn_count) {
                cin >> turn_time >> turn;
                turn_count--;
            }
        }
    }
    cout << total_time << endl;
    return 0;
}