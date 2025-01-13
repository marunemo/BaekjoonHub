#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    cout.precision(13);
    cout << fixed << sqrt(a * a + b * b) << endl;
    return 0;
}