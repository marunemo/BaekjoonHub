#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string zhivago;

    cin >> n;
    cout << (n - 1) % 4 << endl;

    // remove '\n'
    cin.ignore();

    while(true) {
        getline(cin, zhivago);
        if(zhivago == "I give up")
            break;
        
        cout << (4 - (zhivago[0] - '0')) << endl;
    }
    return 0;
}