#include <iostream>

using namespace std;
using pii = pair<int, int>;

int board[20][20];

int DivideCount(int h_start, int h_end, int w_start, int w_end, bool is_vertical) {
    bool contain_imp, contain_jwl;
    int count = 0;
    int imp_count = 0;
    int jwl_count = 0;
    
    if(is_vertical) {
        for(int w = w_start; w <= w_end; w++) {
            contain_imp = false;
            contain_jwl = false;
            for(int h = h_start; h <= h_end; h++) {
                if(board[h][w] == 1) {
                    contain_imp = true;
                    imp_count++;
                }
                if(board[h][w] == 2) {
                    contain_jwl = true;
                    jwl_count++;
                }
            }

            if(contain_imp && !contain_jwl)
                count += DivideCount(h_start, h_end, w_start, w - 1, !is_vertical) * DivideCount(h_start, h_end, w + 1, w_end, !is_vertical);
        }
    }
    else {
        for(int h = h_start; h <= h_end; h++) {
            contain_imp = false;
            contain_jwl = false;
            for(int w = w_start; w <= w_end; w++) {
                if(board[h][w] == 1) {
                    contain_imp = true;
                    imp_count++;
                }
                if(board[h][w] == 2) {
                    contain_jwl = true;
                    jwl_count++;
                }
            }

            if(contain_imp && !contain_jwl)
                count += DivideCount(h_start, h - 1, w_start, w_end, !is_vertical) * DivideCount(h + 1, h_end, w_start, w_end, !is_vertical);
        }
    }

    if(!imp_count) {
        if(jwl_count == 1)
            return 1;
        else
            return 0;
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