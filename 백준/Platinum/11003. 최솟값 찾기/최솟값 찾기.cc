#include <iostream>
#include <unordered_map>

using namespace std;

int arr[5000000];
int range_min[5000000 * 2 + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, l;
    int first_min;
    
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    first_min = arr[0];
    for(int i = 0; i < l; i++) {
        first_min = min(first_min, arr[i]);
        cout << first_min << ' ';
    }
    for(int i = l; i < n; i += l) {
        range_min[l] = arr[i];
        for(int j = 1; j <= l; j++)
            range_min[l - j] = min(arr[i - j], range_min[l - j + 1]);
        for(int j = 1; j <= l && i + j < n; j++)
            range_min[l + j] = min(arr[i + j], range_min[l + j - 1]);
        
        for(int j = l - 1; j >= 0 && i - (j - l + 1) < n; j--)
            cout << min(range_min[l - j], range_min[l - (j - l + 1)]) << ' ';
    }
    return 0;
}