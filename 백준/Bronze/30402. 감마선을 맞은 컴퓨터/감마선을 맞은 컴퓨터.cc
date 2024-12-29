#include <iostream>

using namespace std;

int main() {
    char pixel;
    int idx;

    for(int i = 0; i < 15 * 15; i++) {
        cin >> pixel;
        if(pixel == 'w')
            idx = 1;
        else if(pixel == 'b')
            idx = 2;
        else if(pixel == 'g')
            idx = 3;
    }

    if(idx == 1)
        cout << "chunbae";
    else if(idx == 2)
        cout << "nabi";
    else if(idx == 3)
        cout << "yeongcheol";
    cout << endl;
    return 0;
}