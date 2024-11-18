#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

bool Compare(pii a, pii b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    vector<pii> a, b;
    vector<int> result;
    int a_idx = -1, b_idx = -1;

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    cin >> m;
    b.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(a.begin(), a.end(), Compare);
    sort(b.begin(), b.end(), Compare);

    for(int a_i = 0, b_i = 0; a_i < n && b_i < m; ) {
        if(a_idx > a[a_i].second)
            a_i++;
        else if(b_idx > b[b_i].second)
            b_i++;
        else if(a[a_i].first == b[b_i].first) {
            result.push_back(a[a_i].first);
            a_idx = a[a_i].second;
            b_idx = b[b_i].second;
            a_i++, b_i++;
        }
        else if(a[a_i].first > b[b_i].first)
            a_i++;
        else
            b_i++;
    }

    cout << result.size() << '\n';
    for(int num: result)
        cout << num << ' ';
    cout << endl;
    return 0;
}