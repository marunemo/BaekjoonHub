#include <iostream>

using namespace std;

int main() {
    int drink_count;
    float drink;

    float max_drink = 0;
    float total_drink = 0;

    cin >> drink_count;
    while(drink_count--) {
        cin >> drink;

        max_drink = max(drink, max_drink);
        total_drink += drink / 2;
    }
    total_drink += max_drink / 2;

    cout.precision(6);
    cout << fixed;
    cout << total_drink << endl;
    return 0;
}