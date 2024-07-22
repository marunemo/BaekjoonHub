#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> a[200000];
int b[200000];
int result[200000];
bool flag;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second  = i;
    }
    for(int i = 0; i < n; i++)
        cin >> b[i];
    
    sort(a, a + n);
    sort(b, b + n);

    flag = true;
    for(int i = 0; i < n && flag; i++) {
        if(a[i].first > b[i])
            flag = false;
        else
            result[a[i].second] = b[i];
    }

    if(!flag)
        cout << -1 << endl;
    else {
        for(int i = 0; i < n; i++)
            cout << result[i] << ' ';
        cout << endl;
    }
    return 0;
}