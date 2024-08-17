#include <iostream>

using namespace std;

int main() {
    int burger, drink;
    int min_b = 2000, min_d = 2000;

    for(int i = 0; i < 3; i++) {
        cin >> burger;
        min_b = min(min_b, burger);
    }
    for(int i = 0; i < 2; i++) {
        cin >> drink;
        min_d = min(min_d, drink);
    }

    cout << min_b + min_d - 50 << endl;
    return 0;
}