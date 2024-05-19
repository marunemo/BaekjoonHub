#include <iostream>
#include <string>

using namespace std;

bool IsPalin(string str) {
    int len = str.length();

    for(int i = 0; i < len / 2 + len % 2; i++) {
        if(str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string num;

    cin >> num;
    while(num != "0") {
        if(IsPalin(num))
            cout << "yes\n";
        else
            cout << "no\n";
        
        cin >> num;
    }
    return 0;
}