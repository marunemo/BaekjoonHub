#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int min_odd = 100;
    int num;

    for(int i = 0; i < 7; i++) {
        cin >> num;

        if(num % 2) {
            sum += num;
            min_odd = min(min_odd, num);
        }
    }

    if(min_odd % 2)
        cout << sum << '\n' << min_odd << endl;
    else
        cout << -1 << endl;
    return 0;
}