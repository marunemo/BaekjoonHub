#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> mul;

ll IsPrime(ll n) {
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return i;
    }
    return n;
}

int main() {
    ll n, i, element = 1;

    cin >> n;
    while(n > 1) {
        i = IsPrime(n);
        if(element == 1)
            element = i;
        else {
            mul.push_back(element * i);
            element = 1;
        }
        n /= i;
    }
    if(mul.empty())
        mul.push_back(n);
    else {
        element *= mul.back();
        mul.pop_back();
        mul.push_back(element);
    }


    if(mul.back() == n)
        cout << -1 << endl;
    else {
        for(ll num: mul)
            cout << num << ' ';
        cout << endl;
    }
    return 0;
}