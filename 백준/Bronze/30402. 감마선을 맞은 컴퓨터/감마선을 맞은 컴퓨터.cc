#include <iostream>

using namespace std;

int main() {
    char pixel;

    for(int i = 0; i < 15 * 15; i++) {
        cin >> pixel;
        if(pixel == 'w') {
            cout << "chunbae" << endl;
            return 0;
        }
        else if(pixel == 'b') {
            cout << "nabi" << endl;
            return 0;
        }
        else if(pixel == 'g') {
            cout << "yeongcheol" << endl;
            return 0;
        }
    }
    return 0;
}