#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int arr[1000000];
unordered_map<int, int> count;
int ngf[1000000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int index;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        count[arr[i]]++;
    }

    for(int i = n - 1; i >= 0; i--) {
        for(index = i + 1; index < n && count[arr[index]] <= count[arr[i]]; index = ngf[index]);
        ngf[i] = index;
    }

    for(int i = 0; i < n; i++) {
        if(ngf[i] == n)
            cout << -1 << ' ';
        else
            cout << arr[ngf[i]] << ' ';
    }
    cout << endl;
    return 0;
}