#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100000];
int b[100000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int sum_b = 0;
    bool flag = true;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];

    sort(arr, arr + n, greater<int>());
    sort(b, b + m, greater<int>());

    for(int i = 0, choice = m; i < m && flag; i++, choice--) {
        for(int j = sum_b; j < sum_b + b[i] && flag; j++)
            flag = arr[j] >= choice;
        sum_b += b[i];
    }

    if(flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}