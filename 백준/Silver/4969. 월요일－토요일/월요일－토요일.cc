#include <iostream>

using namespace std;

bool mon_sat[300001] = {false};
bool ms_prime[300001] = {false};

// 사실, 월요일-토요일 숫자 a가 b의 약수(일반적인 약수)라면, a는 b의 월요일-토요일 약수이다. 또, 역도 성립한다.
bool IsPrime(int ms) {
    for(int i = 2; i * i <= ms; i++) {
        if(mon_sat[i] && ms % i == 0)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    // mon
    for(int i = 1; i <= 300000; i += 7)
        mon_sat[i] = true;
    
    // sat
    for(int i = 6; i <= 300000; i += 7)
        mon_sat[i] = true;

    // prime
    for(int i = 1; i <= 300000; i++) {
        if(mon_sat[i])
            ms_prime[i] = IsPrime(i);
    }

    int num;
    cin >> num;

    while(num != 1) {
        cout << num << ": ";
        for(int i = 2; i <= num; i++) {
            if(mon_sat[i] && ms_prime[i] && num % i == 0)
                cout << i << ' ';
        }
        cout << '\n';

        cin >> num;
    }
    return 0;
}