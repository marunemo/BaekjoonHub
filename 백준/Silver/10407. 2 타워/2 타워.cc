#include <iostream>

using namespace std;

int main() {
    char h[102];
    cin >> h;

    cout << (!h[1] & (h[0] == 49)) + 1 << endl;
    return 0;
}