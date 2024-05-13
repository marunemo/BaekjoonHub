#include <iostream>

using namespace std;

int main() {
    long long num;
    long long len;
    long long sum = 0;

    cin >> num;
    for(len = 1; sum + len <= num; len++)
        sum += len;
    cout << (len - 1) << endl;
    return 0;
}