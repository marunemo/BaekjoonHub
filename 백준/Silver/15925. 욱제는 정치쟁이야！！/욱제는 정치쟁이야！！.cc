#include <iostream>

using namespace std;

int main() {
    int n, use;
    char turn;
    bool com[31][31];
    bool flag;
    int count;

    cin >> n >> use;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> turn;
            com[i][j] = (turn == '1');
        }
    }

    do {
        flag = false;
        for(int row = 0; row < n; row++) {
            count = 0;
            for(int col = 0; col < n; col++) {
                if(use ^ com[row][col] == 0)
                    count++;
            }

            if(count > n / 2 && count != n) {
                flag = true;
                for(int col = 0; col < n; col++)
                    com[row][col] = use;
            }
        }

        for(int col = 0; col < n; col++) {
            count = 0;
            for(int row = 0; row < n; row++) {
                if(use ^ com[row][col] == 0)
                    count++;
            }

            if(count > n / 2 && count != n) {
                flag = true;
                for(int row = 0; row < n; row++)
                    com[row][col] = use;
            }
        }
    } while(flag);

    flag = true;
    for(int row = 0; row < n && flag; row++) {
        for(int col = 0; col < n && flag; col++) {
            if(com[row][col] ^ use)
                flag = false;
        }
    }

    cout << flag << endl;
    return 0;
}