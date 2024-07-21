#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, a[1000];
    int s = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());

    for(int i = 0; i < n / 2; i++)
        s += a[i];
    cout << s << endl;
    return 0;
}