#include <iostream>
#define MOD 1000000009

using namespace std;
using ll = long long;

ll method[100001][4] = {0};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    method[1][1] = method[2][2] = method[3][3] = 1;
    for(int i = 1; i <= 100000; i++) {
        if(i >= 1)
            method[i][1] += method[i - 1][2] + method[i - 1][3];
        if(i >= 2)
            method[i][2] += method[i - 2][1] + method[i - 2][3];
        if(i >= 3)
            method[i][3] += method[i - 3][1] + method[i - 3][2];
        
        method[i][1] %= MOD;
        method[i][2] %= MOD;
        method[i][3] %= MOD;
    }

    int tc, len;

    cin >> tc;
    while(tc--) {
        cin >> len;
        cout << (method[len][1] + method[len][2] + method[len][3]) % MOD << '\n';
    }
    return 0;
}