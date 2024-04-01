#include <iostream>
#define power(x) (x) * (x)

using namespace std;

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int x1, y1, r1;
    int x2, y2, r2;

    cin >> tc;
    for(int i = 0;  i < tc; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int distance = power(x2 - x1) + power(y2 - y1);
        if(x1 == x2 && y1 == y2 && r1 == r2)
            cout << -1 << '\n';
        else if(distance < power(r1 + r2) && distance > power(r1 - r2))
            cout << 2 << '\n';
        else if(distance == power(r1 + r2) || distance == power(r1 - r2))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}