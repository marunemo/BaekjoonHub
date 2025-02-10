#include <iostream>

using namespace std;

int main() {
    int n, num;

    cin >> n;
    for(int i = 1; n; i++) {
        while(n--)
            cin >> num;
        cout << "Case " << i << ": Sorting... done!\n";
        cin >> n;
    }
    return 0;
}