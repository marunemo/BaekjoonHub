#include <iostream>
#include <string>

using namespace std;

int main() {
    int i = 0;
    string str;

    while(getline(cin, str))
        i++;
    cout << i << endl;
    return 0;
}