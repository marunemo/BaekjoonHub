#include <iostream>

using namespace std;

int main() {
    int n;
    bool sk_win[1001] = {false, true, false, true};

    cin >> n;
    for(int i = 4; i <= n; i++)
        sk_win[i] = (!sk_win[i - 1]) || (!sk_win[i - 3]);
    
    if(sk_win[n])
        cout << "SK" << endl;
    else
        cout << "CY" << endl;
    return 0;
}