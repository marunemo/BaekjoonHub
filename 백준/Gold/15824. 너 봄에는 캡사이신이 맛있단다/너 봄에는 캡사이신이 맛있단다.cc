#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;
using ll = long long;

ll arr[300005];
ll two[300005];

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    ll n;
    ll temp = 1;
    ll p = 0, m = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        two[i] = temp - 1;
        temp *= 2;
        temp %= MOD;
    }

    sort(arr, arr + n);

    for (int i = n - 1; i > 0; i--) {
        p += two[i] * arr[i];
        m += two[i] * arr[n - 1 - i];
        p %= MOD;
        m %= MOD;
    }
    cout << (p % MOD + MOD - m % MOD) % MOD << '\n';
    return 0;
}