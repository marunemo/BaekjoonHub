#include <iostream>

using namespace std;

int main() {
    bool prime[1001] = {0};
    int n, num, count = 0;
    bool is_prime;

    for(int i = 2; i <= 1000; i++) {
        is_prime = true;
        for(int j = 2; j * j <= i && is_prime; j++)
            is_prime &= (i % j != 0);
        prime[i] = is_prime;
    }

    cin >> n;
    while(n--) {
        cin >> num;
        count += prime[num];
    }
    cout << count << endl;
    return 0;
}