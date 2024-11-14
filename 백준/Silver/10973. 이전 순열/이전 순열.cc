#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[10000];
    bool found[10001] = {0};
    int idx;
    bool asc = true;
    bool flag;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    found[arr[n - 1]] = true;
    for(idx = n - 2; idx >= 0 && asc; idx -= asc) {
        asc = arr[idx] < arr[idx + 1];
        found[arr[idx]] = true;
    }
    
    if(idx == -1)
        cout << -1 << endl;
    else {
        flag = false;
        for(int i = arr[idx] - 1; i > 0 && !flag; i--) {
            if(found[i]) {
                arr[idx++] = i;
                found[i] = false;
                flag = true;
            }
        }

        if(!flag) {
            found[arr[--idx]] = true;
            for(int i = arr[idx] - 1; i > 0 && !flag; i--) {
                if(found[i]) {
                    arr[idx++] = i;
                    found[i] = false;
                    flag = true;
                }
            }
        }

        for(int i = n; i > 0; i--) {
            if(found[i])
                arr[idx++] = i;
        }

        for(int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }
    return 0;
}