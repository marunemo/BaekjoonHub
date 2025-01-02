#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    bool flag;

    cin >> a >> b >> c;
    
    for(int x = 1; x <= 10; x++) {
        flag = false;
        for(int y = 1; y <= 10; y++) {
            if(a * x + b * y == c) {
                cout << y << ' ';
                flag = true;
            }
        }

        if(!flag)
            cout << 0;
        cout << '\n';
    }
    return 0;
}