#include <iostream>

using namespace std;
using ll = long long;
using Pos = pair<ll, ll>;

ll CCW(Pos a, Pos b, Pos c) {
    ll o_product = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
    return o_product / max(1LL, abs(o_product));
}

int main() {
    Pos a, b, c, d;
    ll ccw1, ccw2;
    
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    cin >> d.first >> d.second;

    ccw1 = CCW(a, b, c) * CCW(a, b, d);
    ccw2 = CCW(c, d, a) * CCW(c, d, b);

    cout << (bool)(ccw1 <= 0 && ccw2 <= 0) << endl;
    return 0;
}