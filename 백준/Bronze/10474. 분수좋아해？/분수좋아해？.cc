#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int numerator, denominator;

    cin >> numerator >> denominator;
    while(numerator != 0 && denominator != 0) {
        cout << (numerator / denominator) << ' ' << (numerator % denominator) << " / " << denominator << '\n';
        cin >> numerator >> denominator;
    }
    return 0;
}