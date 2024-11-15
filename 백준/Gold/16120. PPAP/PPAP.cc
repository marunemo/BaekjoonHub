#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string str;
    stack<char> ppap;
    bool flag = false;

    cin >> str;
    for(char c: str) {
        ppap.push(c);

        if(c == 'A') {
            if(flag) {
                cout << "NP" << endl;
                return 0;
            }
            flag = true;
        }
        else if(flag) {
            if(ppap.size() < 4) {
                cout << "NP" << endl;
                return 0;
            }

            for(int i = 0; i < 4; i++)
                ppap.pop();
            ppap.push('P');
            flag = false;
        }
    }

    if(flag || ppap.size() != 1)
        cout << "NP" << endl;
    else
        cout << "PPAP" << endl;
    return 0;
}