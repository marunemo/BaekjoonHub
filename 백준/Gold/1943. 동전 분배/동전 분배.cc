#include <iostream>
#define MAX 100000

using namespace std;

bool price[100001];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int coin_count;
    int money, count;
    int sum;

    for(int tc = 0; tc < 3; tc++) {
        for(int p = 0; p <= MAX; p++)
            price[p] = false;
        price[0] = true;
        sum = 0;

        cin >> coin_count;
        while(coin_count--) {
            cin >> money >> count;
            sum += money * count;

            for(int p = MAX - money; p >= 0; p--) {
                if(!price[p])
                    continue;
                
                for(int i = 1; i <= count && p + money * i <= MAX && !price[p + money * i]; i++)
                    price[p + money * i] = true;
            }
        }

        if(sum % 2)
            cout << 0 << '\n';
        else
            cout << price[sum / 2] << '\n';
    }
    return 0;
}