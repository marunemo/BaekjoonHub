#include <iostream>

using namespace std;
using ll = long long;

// x_i와 i는 고정
// i - j > 0이고 x_i - x_j는 대소관계가 제각각이므로
// (x_i - c_i) - x_j + c_j이나 (-x_i - c_i) + x_j + c_j의 최댓값
ll result[400001];

int main() {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    
    int n, c;
    ll x_i;
    ll big_xj, small_xj;

    cin >> n >> c;

    // i == 1
    cin >> x_i;
    big_xj = x_i + c;
    small_xj = -1 * x_i + c;
    result[1] = 0;

    for(ll i = 2; i <= n; i++) {
        cin >> x_i;

        if(big_xj < x_i + c * i)
            big_xj = x_i + c * i;
        if(small_xj < -1 * x_i + c * i)
            small_xj = -1 * x_i + c * i;
        
        result[i] = max(x_i - c * i + small_xj, -1 * x_i - c * i + big_xj);
    }

    for(int i = 1; i <= n; i++) {
        cout << result[i];
        if(i == n)
            cout << '\n';
        else
            cout << ' ';
    }
    return 0;
}