#include <iostream>

using namespace std;

bool IsPrime(int num) {
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int prime_count[123456 * 2  + 1] = {0};
    int n;
    
    for(int num = 2; num <= 123456 * 2; num++)
        prime_count[num] = IsPrime(num) + prime_count[num - 1];
    
    cin >> n;
    while(n) {
        cout << (prime_count[n * 2] - prime_count[n]) << '\n';
        cin >> n;
    }
    return 0;
}