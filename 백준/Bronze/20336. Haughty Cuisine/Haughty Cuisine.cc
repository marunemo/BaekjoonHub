#include <iostream>

using namespace std;

char set[42][21];

int main() {
    int n, d;

    cin >> n;
    while(n--) {
        cin >> d;
        for(int i = 0; i < d; i++)
            cin >> set[i];
    }

    cout << d << '\n';
    for(int i = 0; i < d; i++)
        cout << set[i] << '\n';
    return 0;
}