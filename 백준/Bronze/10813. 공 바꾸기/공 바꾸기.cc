#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int basket[101];
    int n, m, i, j;

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        basket[i] = i;
    while(m--) {
        cin >> i >> j;
        if(i != j)
            basket[i] ^= basket[j] ^= basket[i] ^= basket[j];
    }
    for(int i = 1; i <= n; i++)
        cout << basket[i] << ' ';
    cout << '\n';
    return 0;
}