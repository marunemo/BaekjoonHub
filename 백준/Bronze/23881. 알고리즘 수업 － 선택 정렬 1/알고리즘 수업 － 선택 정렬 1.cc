#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int a[10000];
pair<int, int> sorted[10000];
int a_index[10000];

void Swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int count = 0;
    int new_index;

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sorted[i] = {a[i], i};
    }

    sort(sorted, sorted + n);
    for(int i = 0; i < n; i++)
        a_index[sorted[i].second] = i;

    for(int i = n - 1; i >= 0 && count < k; i--) {
        new_index = sorted[i].second;
        if(a[i] == a[new_index])
            continue;

        if(++count == k) {
            cout << a[i] << ' ' << a[new_index] << endl;
            break;
        }
        Swap(a[i], a[new_index]);
        Swap(sorted[i].second, sorted[a_index[i]].second);
        a_index[new_index] = a_index[i];
        a_index[i] = i;

    }

    if(count < k)
        cout << -1 << endl;
    return 0;
}