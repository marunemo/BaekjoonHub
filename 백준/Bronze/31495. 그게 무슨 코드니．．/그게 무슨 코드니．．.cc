#include <iostream>
#include <string>

using namespace std;

int main() {
    string code;
    int left, right;

    // read line
    getline(cin, code);

    left = 0;
    right = code.length() - 1;

    if(left + 1 >= right)
        cout << "CE";
    else if(code[left] != '\"' || code[right] != '\"')
        cout << "CE";
    else {
        for(left = left + 1; left < right; left++)
            cout << code[left];
    }
    cout << endl;
    return 0;
}