#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int n;
    pair<ll, ll> sb[10];
    pair<ll, ll> sb_sum;
    ll min_diff = 1000000000000000;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> sb[i].first >> sb[i].second;
    for(int mask = 1; mask < (1 << n); mask++) {
        sb_sum = {1, 0};
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                sb_sum.first *= sb[i].first;
                sb_sum.second += sb[i].second;
            }
        }
        min_diff = min(min_diff, abs(sb_sum.first - sb_sum.second));
    }
    cout << min_diff << endl;
    return 0;
}