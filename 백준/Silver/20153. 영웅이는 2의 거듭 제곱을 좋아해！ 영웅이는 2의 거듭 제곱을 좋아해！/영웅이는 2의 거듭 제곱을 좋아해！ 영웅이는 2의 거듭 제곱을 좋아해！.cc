#include <iostream>
#define MAX 2222222

using namespace std;
using ll = long long;

ll arr[MAX];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    ll sum = 0;
    ll max_sum = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum ^= arr[i];
    }
    max_sum = sum;
    for(int i = 0; i < n; i++) {
        sum ^= arr[i];
        max_sum = max(sum, max_sum);
        sum ^= arr[i];
    }

    cout << max_sum << max_sum << endl;
    return 0;
}