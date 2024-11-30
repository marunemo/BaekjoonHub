#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int query_count, query, x, bit = 0;
    long long sum = 0;

    cin >> query_count;
    while(query_count--) {
        cin >> query;

        if(query == 1) {
            cin >> x;
            sum += x;
            bit ^= x;
        }
        else if(query == 2) {
            cin >> x;
            sum -= x;
            bit ^= x;
        }
        else if(query == 3)
            cout << sum << '\n';
        else if(query == 4)
            cout << bit << '\n';
    }
    return 0;
}