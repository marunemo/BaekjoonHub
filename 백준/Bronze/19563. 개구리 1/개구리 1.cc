#include <iostream>

using namespace std;

int main() {
    long long a, b, c;

    cin >> a >> b >> c;
    
    a = abs(a);
    b = abs(b);
    
    if(a + b > c || abs(a + b - c) % 2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}