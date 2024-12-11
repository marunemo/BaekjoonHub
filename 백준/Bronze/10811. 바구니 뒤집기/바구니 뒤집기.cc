#include <iostream>

using namespace std;

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m, a, b;
    int arr[101];

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        arr[i] = i;

    while(m--) {
        cin >> a >> b;
        for(int left = a, right = b; left < right; left++, right--)
            Swap(arr[left], arr[right]);
    }

    for(int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}