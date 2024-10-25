#include <iostream>

using namespace std;

int main() {
    int flag;
    int a, b;

    flag = false;
    for(a = 1; a <= 9 && !flag; a += !flag) {
        cout << "? A " << a << endl;
        cin >> flag;
    }

    flag = false;
    for(b = 1; b <= 9 && !flag; b += !flag) {
        cout << "? B " << b << endl;
        cin >> flag;
    }

    cout << "! " << (a + b) << endl;
    return 0;
}