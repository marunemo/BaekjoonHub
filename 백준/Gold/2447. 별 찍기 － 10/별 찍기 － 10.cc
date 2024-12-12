#include <iostream>

using namespace std;

bool star[81*81][81*81] = {0};

void Recursion(int n, int r_start, int c_start) {
    if(n == 1) {
        star[r_start][c_start] = true;
        return;
    }
    
    for(int i = 0; i < n; i += n / 3) {
        for(int j = 0; j < n; j += n / 3) {
            if(i == n / 3 && j == n / 3)
                continue;

            Recursion(n / 3, r_start + i, c_start + j);
        }
    }
}

int main() {
    int n;

    cin >> n;
    Recursion(n, 0, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(star[i][j])
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}