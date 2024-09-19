#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

short stock[1000000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int date;
    short max_stock;
    ll benefit;

    cin >> tc;
    while(tc--) {
        cin >> date;

        for(int i = 0; i < date; i++)
            cin >> stock[i];
        
        benefit = 0;
        max_stock = stock[date - 1];
        for(int i = date - 2; i >= 0; i--) {
            if(max_stock < stock[i])
                max_stock = stock[i];
            else
                benefit += (ll)max_stock - stock[i];
        }

        cout << benefit << '\n';
    }
    return 0;
}