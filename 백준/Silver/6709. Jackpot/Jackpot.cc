#include <iostream>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, w, p[5];
    ll lcm;
    
    cin >> n;
    while(n--) {
        cin >> w;
        for(int i = 0; i < w; i++)
            cin >> p[i];

        lcm = 1;
        for(int i = 0; i < w; i++) {
            lcm = lcm * p[i] / gcd(lcm, p[i]);
            if(lcm > 1e9)
            break;
        }
        
        if(lcm <= 1e9)
            cout << lcm << '\n';
        else
            cout << "More than a billion.\n";
    }

    return 0;
}