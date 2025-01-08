#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int a, b, c;

    cin >> tc;
    while(tc--) {
        cin >> a >> b >> c;
        cout << min(min(a, b), c) << '\n';
    }
    return 0;
}