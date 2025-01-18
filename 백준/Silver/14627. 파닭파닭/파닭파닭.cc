#include <iostream>

using namespace std;
using ll = long long;

ll len[1000000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int s, c;
    ll max_len = 0;
    ll left, right, mid;
    ll answer = 0;

    cin >> s >> c;
    for(int i = 0; i < s; i++) {
        cin >> len[i];
        max_len = max(len[i], max_len);
    }
    
    left = 1;
    right = max_len;
    max_len = 0;
    for(ll count = 0, candidate = 0; left <= right; count = 0, candidate = 0) {
        mid = (left + right) / 2;

        for(int i = 0; i < s; i++) {
            if(count + len[i] / mid <= c) {
                candidate += len[i] % mid;
                count += len[i] / mid;
            }
            else {
                candidate += len[i] - (c - count) * mid;
                count = c;
            }
        }

        if(count == c) {
            if(max_len < mid) {
                max_len = mid;
                answer = candidate;
            }
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}