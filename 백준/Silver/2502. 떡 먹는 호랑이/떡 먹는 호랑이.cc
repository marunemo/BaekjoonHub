#include <iostream>

using namespace std;

int main() {
    int d, k;
    int a = 1, b = 1;
    int tmp;

    cin >> d >> k;
    d -= 3;
    for(int i = 0; i < d; i++) {
        tmp = a;
        a = b;
        b += tmp;
    }

    for(int i = 1; ; i++) {
        if((k - (a * i)) % b == 0) {
            cout << i << '\n' << (k - (a * i)) / b << endl;
            return 0;
        }
    }
    return 0;
}