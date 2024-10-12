#include <iostream>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    int a[10000];
    int b[10000];
    pii sorted[10000];
    int index[10000];
    bool flag = 1;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sorted[i] = {a[i], i};
    }
    for(int i = 0; i < n; i++)
        cin >> b[i];

    sort(sorted, sorted + n);
    for(int i = 0; i < n; i++)
        index[sorted[i].second] = i;

    for(int i = n - 1; i >= 0 && flag; i--) {
        if(a[i] == b[i])
            continue;
        
        Swap(a[i], a[sorted[i].second]);
        Swap(sorted[i].second, sorted[index[i]].second);
        Swap(index[i], index[sorted[index[i]].second]);

        if(a[i] != b[i])
            flag = false;
    }
    cout << flag << endl;
    return 0;
}