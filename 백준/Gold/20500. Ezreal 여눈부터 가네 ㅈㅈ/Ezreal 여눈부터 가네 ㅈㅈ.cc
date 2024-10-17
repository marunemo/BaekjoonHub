#include <iostream>

using namespace std;

int main() {
    int n;
    int count[2][6][3] = {0};
    bool flag;

    cin >> n;
    count[0][1][1] = 1;
    count[0][5][2] = 1;
    flag = true;

    for(int i = 2; i <= n; i++) {
        for(int mod = 0; mod < 3; mod++) {
            count[flag][1][mod] = (count[!flag][1][(mod + 1) % 3] + count[!flag][5][(mod + 1) % 3]) % 1000000007;
            count[flag][5][mod] = (count[!flag][1][(mod + 5) % 3] + count[!flag][5][(mod + 5) % 3]) % 1000000007;
        }
        flag = !flag;
    }

    cout << count[!flag][5][0] << endl;
    return 0;
}