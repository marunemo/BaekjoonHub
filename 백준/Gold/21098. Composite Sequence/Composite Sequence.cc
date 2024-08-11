#include <iostream>

using namespace std;
using ll = long long;

bool IsPrime(ll num) {
    for(ll i = 2; i * i <= num; i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    ll s[100000];

    int odd = 0;
    int even = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        
        if(s[i] % 2)
            odd++;
        else
            even++;
    }
    
    if(n >= 4)
        cout << "Yes" << endl;
    else if(even >= 2)
        cout << "Yes" << endl;
    else if(odd >= 4)
        cout << "Yes" << endl;
    else {
        for(int i = 0; i < n; i++) {
            if(!IsPrime(s[i])) {
                cout << "Yes" << endl;
                return 0;
            }

            for(int j = i + 1; j < n; j++) {
                if(!IsPrime(s[i] + s[j])) {
                    cout << "Yes" << endl;
                    return 0;
                }

                for(int k = j + 1; k < n; k++) {
                    if(!IsPrime(s[i] + s[j] + s[k])) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
        
        cout << "No" << endl;
    }
    
    return 0;
}