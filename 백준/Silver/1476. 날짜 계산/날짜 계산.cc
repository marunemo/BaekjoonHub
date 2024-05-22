#include <iostream>

using namespace std;

int main() {
    int e, s, m;
    int num;

    cin >> e >> s >> m;
    for(num = 1; ; num++) {
        if(num % 15 + 1 == e && num % 28 + 1 == s && num % 19 + 1 == m)
            break;
    }

    cout << (num % 7980 + 1) << endl;
    return 0;
}