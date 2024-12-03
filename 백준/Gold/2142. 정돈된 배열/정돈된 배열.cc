#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int n, m;
    int arr[500][500];
    bool flag;

    cin >> tc;
    while(tc--) {
        cin >> n >> m;

        flag = true;
        for(int k = 0; k < n && flag; k++) {
            for(int l = 0; l < m && flag; l++)
                cin >> arr[k][l];
        }

        for(int k = 1; k < n && flag; k++) {
            for(int l = 1; l < m && flag; l++)
                flag = arr[k - 1][l - 1] + arr[k][l] <= arr[k - 1][l] + arr[k][l - 1];
        }

        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}