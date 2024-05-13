#include <iostream>

using namespace std;

int main() {
    int n;
    int coin[100001] = {0, 1, 1, 2, 2, 1, 2};

    cin >> n;
    for(int i = 7; i <= n; i++) {
        coin[i] = coin[i-1] + 1;
        coin[i] = min(coin[i], coin[i-2] + 1);
        coin[i] = min(coin[i], coin[i-5] + 1);
        coin[i] = min(coin[i], coin[i-7] + 1);
    }

    cout << coin[n] << endl;
    return 0;
}