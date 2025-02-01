#include <iostream>

using namespace std;

int main() {
    int n, num, count = 0;
    cin >> n;
    while(n--) {
        cin >> num;
        count += num & 1;
    }
    cout << count << endl;
    return 0;
}