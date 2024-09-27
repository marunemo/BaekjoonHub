#include <iostream>

using namespace std;

const char moo[4] = "moo";

void DivideConquer(int &n, int depth, int len) {
    if(n <= 3) {
        cout << moo[n - 1] << endl;
        return;
    }
    
    int next_len = len * 2 + depth + 4;
    if(next_len < n)
        DivideConquer(n, depth + 1, next_len);
    else {
        if(len < n && n <= len + depth + 4) {
            if(n - len == 1)
                cout << "m" << endl;
            else
                cout << "o" << endl;
            return;
        }
        else {
            n -= len + depth + 4;
            DivideConquer(n, 0, 3);
        }
    }
}

int main() {
    int n;
    cin >> n;

    DivideConquer(n, 0, 3);
    return 0;
}