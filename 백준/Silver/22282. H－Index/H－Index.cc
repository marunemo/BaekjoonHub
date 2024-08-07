#include <iostream>
#include <algorithm>

using namespace std;

int n, c[100000], h;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);

    for(h = 1; h <= n && c[n - h] >= h; h++);
    cout << (h - 1) << endl;
    return 0;
}