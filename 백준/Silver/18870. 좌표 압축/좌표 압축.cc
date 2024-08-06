#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, num[1000000];
int sorted[1000000];
unordered_map<int, int> compress;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int idx = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        sorted[i] = num[i];
    }
    sort(sorted, sorted + n);

    for(int i = 0; i < n; i++) {
        if(!compress[sorted[i]])
            compress[sorted[i]] = ++idx;
    }

    for(int i = 0; i < n; i++)
        cout << (compress[num[i]] - 1) << ' ';
    cout << endl;
    return 0;
}