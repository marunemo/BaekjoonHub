#include <iostream>

using namespace std;

int main() {
    int n;
    long long tile[31] = {1, 0, 3, 0};
    
    cin >> n;

    for(int i = 4; i <= n; i++) {
        tile[i] = tile[i - 2] * 3;
        for(int j = i - 4; j >= 0; j -= 2)
            tile[i] += tile[j] * 2;
    }
    cout << tile[n] << endl;
    return 0;
}