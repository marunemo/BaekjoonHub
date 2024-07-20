#include <iostream>

using namespace std;
using ll = long long;

ll GCD(ll a, ll b) {
    if(a % b == 0)
        return b;
    return GCD(b, a % b);
}

int main() {
    ll n;
    ll a[50], b[50];
    ll gcd, lcm = 1;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];

        gcd = GCD(a[i], b[i]);
        a[i] /= gcd;
        b[i] /= gcd;

        gcd = GCD(lcm, b[i]);
        lcm = lcm * b[i] / gcd;
    }

    gcd = a[0] * lcm / b[0];
    for(int i = 1; i < n; i++) {
        a[i] *= lcm / b[i];
        gcd = GCD(gcd, a[i]);
    }

    cout << gcd << ' ' << lcm << endl;
    return 0;
}