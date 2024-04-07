#include <iostream>

using namespace std;
using pii = pair<int, int>;

int board[20][20];

pii CheckStatus(int h_start, int h_end, int w_start, int w_end) {
    pii result = {0, 0};
    for(int h = h_start; h <= h_end; h++) {
        for(int w = w_start; w <= w_end; w++) {
            if(board[h][w] == 1)
                result.first++;
            else if(board[h][w] == 2)
                result.second++;
        }
    }
    return result;
}

int DivideCount(int h_start, int h_end, int w_start, int w_end, bool is_vertical) {
    pii status = CheckStatus(h_start, h_end, w_start, w_end);
    int count = 0;
    bool contain_imp, contain_jwl;

    if(status.first != status.second - 1)
        return 0;
    
    if(status.first == 0 && status.second == 1)
        return 1;
    
    if(is_vertical) {
        for(int w = w_start; w <= w_end; w++) {
            contain_jwl = false;
            for(int h = h_start; h <= h_end; h++) {
                if(board[h][w] == 1)
                    contain_imp = true;
                if(board[h][w] == 2)
                    contain_jwl = true;
            }

            if(contain_imp && !contain_jwl)
                count += DivideCount(h_start, h_end, w_start, w - 1, !is_vertical) * DivideCount(h_start, h_end, w + 1, w_end, !is_vertical);
        }
    }
    else {
        for(int h = h_start; h <= h_end; h++) {
            contain_jwl = false;
            for(int w = w_start; w <= w_end; w++) {
                if(board[h][w] == 1)
                    contain_imp = true;
                if(board[h][w] == 2)
                    contain_jwl = true;
            }

            if(contain_imp && !contain_jwl)
                count += DivideCount(h_start, h - 1, w_start, w_end, !is_vertical) * DivideCount(h + 1, h_end, w_start, w_end, !is_vertical);
        }
    }

    return count;
}

int main() {
    int n;
    int count = 0;

    cin >> n;
    for(int h = 0; h < n; h++) {
        for(int w = 0; w < n; w++)
            cin >> board[h][w];
    }

    count += DivideCount(0, n - 1, 0, n - 1, true);
    count += DivideCount(0, n - 1, 0, n - 1, false);

    if(!count)
        count = -1;
    cout << count << endl;
    return 0;
}