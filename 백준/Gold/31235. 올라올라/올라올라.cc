#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, a, max_a, k = 1, max_k = 1;

    cin >> n >> a;
    max_a = a;
    while(--n) {
        cin >> a;
        if(max_a > a)
            k++;
        else {
            max_a = a;
            max_k = max(k, max_k);
            k = 1;
        }
    }
    max_k = max(k, max_k);

    cout << max_k << endl;
    return 0;
}