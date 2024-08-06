#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
int a[500000];
int b[500000];
int comp[1000000];
unordered_map<int, int> compress;
pair<int, int> sorted[500000];
int a_index[500000];

void Swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

bool IsSame() {
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int comp_idx = 0;
    int new_index;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        comp[i] = a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        comp[n + i] = b[i];
    }

    sort(comp, comp + 2 * n);
    for(int i = 0; i < 2 * n; i++) {
        if(!compress[comp[i]])
            compress[comp[i]] = ++comp_idx;
    }
    for(int i = 0; i < n; i++) {
        a[i] = compress[a[i]] - 1;
        b[i] = compress[b[i]] - 1;
        sorted[i] = {a[i], i};
    }

    if(IsSame()) {
        cout << 1 << endl;
        return 0;
    }

    sort(sorted, sorted + n);
    for(int i = 0; i < n; i++)
        a_index[sorted[i].second] = i;

    for(int i = n - 1; i >= 0; i--) {
        new_index = sorted[i].second;
        if(a[i] == a[new_index])
            continue;

        Swap(a[i], a[new_index]);
        Swap(sorted[i].second, sorted[a_index[i]].second);
        a_index[new_index] = a_index[i];
        a_index[i] = i;
        
        if(IsSame()) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << IsSame() << endl;
    return 0;
}