#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, i;
    string handle[100];

    cin >> n >> i;
    for(int idx = 0; idx < n; idx++)
        cin >> handle[idx];
    sort(handle, handle + n);

    cout << handle[i - 1] << endl;
    return 0;
}