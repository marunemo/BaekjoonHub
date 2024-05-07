#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n;
    ll result = 1;

    cin >> n;

    if(n % 2)
        n++;
    for(ll i = n - 1; i > 0; i -= 2)
        result *= i;

    cout << result << endl;
    return 0;
}