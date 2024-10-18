#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> arr;
    vector<int> bundle;
    int start = 0;
    int size;

    cin >> n;

    arr.resize(n);
    cin >> arr[0];
    for(int i = 1; i < n; i++) {
        cin >> arr[i];
        if(arr[i] && arr[i - 1] == arr[i]) {
            bundle.push_back(i - start);
            start = i;
        }
    }
    bundle.push_back(n - start);

    size = bundle.size();
    if(size == 2 && arr[0] && arr[0] == arr[n - 1]) {
        bundle[1]--;

        if(bundle[1] == 0) {
            cout << -1 << endl;
            return 0;
        }
        
        bundle.push_back(1);
        size = bundle.size();
    }

    cout << size << '\n';
    for(int count: bundle)
        cout << count << ' ';
    cout << '\n';
    for(int i = 1; i <= size; i++) {
        if(i == size)
            cout << i << ' ';
        else {
            cout << (i + 1) << ' ' << i << ' ';
            i++;
        }
    }
    cout << endl;
    return 0;
}