#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int num, days;

    cin >> tc;
    while(tc--) {
        cin >> num >> days;

        cout << num << ' ' << (days + (days * (days + 1)) / 2) << '\n';
    }
    return 0;
}