#include <iostream>

using namespace std;
using ll = long long;

ll a[1000000];
ll b[1000000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    int count = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    
    for(int i = 0; i < n - 1; i++) {
        if(a[i] != b[i]) {
            a[i + 1] ^= a[i] ^ b[i];
            a[i] ^= a[i] ^ b[i];
            count++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << count << endl;
    return 0;
}