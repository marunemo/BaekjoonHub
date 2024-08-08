#include <iostream>

using namespace std;
using ll = long long;

int method[100000][3] = {0};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    // 1 = 1
    method[0][0] = 1;
    // 2 = 2
    method[1][1] = 1;
    // 3 = 2 + 1 = 1 + 2 = 3
    method[2][0] = method[2][1] = method[2][2] = 1;
    for(int i = 3; i < 100000; i++) {
        method[i][0] = ((ll)method[i][0] + method[i - 1][1] + method[i - 1][2]) % 1000000009LL;
        method[i][1] = ((ll)method[i][1] + method[i - 2][0] + method[i - 2][2]) % 1000000009LL;
        method[i][2] = ((ll)method[i][2] + method[i - 3][0] + method[i - 3][1]) % 1000000009LL;
    }

    int tc, len;

    cin >> tc;
    while(tc--) {
        cin >> len;
        cout << ((ll)method[len - 1][0] + method[len - 1][1] + method[len - 1][2]) % 1000000009LL << '\n';
    }
    return 0;
}