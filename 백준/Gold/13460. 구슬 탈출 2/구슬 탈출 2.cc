#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#define D_POS DIRECTION[dir][0] * width + DIRECTION[dir][1]

using namespace std;
using Pos = pair<int, int>;
using Status = pair<string, Pos>;

int height, width;
const int DIRECTION[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void Move(string &board, int &pos, int dir) {
    char tmp;
    if(pos < 0)
        return;

    if(board[pos + D_POS] == '.') {
        tmp = board[pos];
        board[pos] = board[pos + D_POS];
        board[pos + D_POS] = tmp;

        pos += D_POS;
    }
    else if(board[pos + D_POS] == 'O') {
        board[pos] = '.';

        pos = -1;
    }
}

void TiltBoard(string &board, int &red_pos, int &blue_pos, int dir) {
    string previous = "";

    while(previous != board) {
        previous = board;
        Move(board, red_pos, dir);
        Move(board, blue_pos, dir);
    }
}

int main() {
    string line;
    string board = "";
    int red_pos, blue_pos;

    Status top;
    queue<Status> curr;
    queue<Status> next;
    unordered_map<string, bool> check;
    int count;
    bool is_exited;

    cin >> height >> width;
    for(int row = 0; row < height; row++) {
        cin >> line;
        board += line;
    }

    for(int i = 0; i < board.length(); i++) {
        if(board[i] == 'R')
            red_pos = i;
        else if(board[i] == 'B')
            blue_pos = i;
    }

    curr.push({board, {red_pos, blue_pos}});
    check[board] = true;

    count = 1;
    is_exited = false;
    while(!curr.empty() && count <= 10) {
        top = curr.front();
        curr.pop();

        for(int dir = 0; dir < 4; dir++) {
            board = top.first;
            red_pos = top.second.first;
            blue_pos = top.second.second;

            TiltBoard(board, red_pos, blue_pos, dir);
            if(blue_pos == -1)
                continue;
            
            if(red_pos == -1) {
                is_exited = true;
                break;
            }

            if(!check[board]) {
                check[board] = true;
                next.push({board, {red_pos, blue_pos}});
            }
        }

        if(is_exited)
            break;

        if(curr.empty()) {
            curr = next;
            next = queue<Status>();
            count++;
        }
    }

    if(count > 10 || !is_exited)
        count = -1;
    cout << count << endl;
    return 0;
}