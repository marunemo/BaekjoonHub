#include <iostream>

using namespace std;

int main() {
    int money;
    int count = 0;

    cin >> money;
    money = 1000 - money;

    for(; money >= 500; money -= 500)
        count++;
    for(; money >= 100; money -= 100)
        count++;
    for(; money >= 50; money -= 50)
        count++;
    for(; money >= 10; money -= 10)
        count++;
    for(; money >= 5; money -= 5)
        count++;
    for(; money >= 1; money -= 1)
        count++;

    cout << count << endl;
    return 0;
}