#include <iostream>

using namespace std;
using ll = long long;

int method[100001][4] = {0};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    // 1 = 1
    method[1][1] = 1;
    // 2 = 2
    method[2][2] = 1;
    // 3 = 2 + 1 = 1 + 2 = 3
    method[3][1] = method[3][2] = method[3][3] = 1;
    for(int i = 4; i <= 100000; i++) {
        method[i][1] = ((ll)method[i][1] + method[i - 1][2] + method[i - 1][3]) % 1000000009LL;
        method[i][2] = ((ll)method[i][2] + method[i - 2][1] + method[i - 2][3]) % 1000000009LL;
        method[i][3] = ((ll)method[i][3] + method[i - 3][1] + method[i - 3][2]) % 1000000009LL;
    }

    int tc, len;

    cin >> tc;
    while(tc--) {
        cin >> len;
        cout << ((ll)method[len][1] + method[len][2] + method[len][3]) % 1000000009LL << '\n';
    }
    return 0;
}