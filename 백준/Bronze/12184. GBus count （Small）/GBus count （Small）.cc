#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc, n, a, b, p, c;
    int tmp, bus[502] = {0};

    cin >> tc;
    for(int i = 1; i <= tc; i++) {
        for(int i = 1; i <= 500; i++)
            bus[i] = 0;

        cin >> n;
        while(n--) {
            cin >> a >> b;
            if(a > b) {
                tmp = a;
                a = b;
                b = tmp;
            }

            bus[a]++;
            bus[b + 1]--;
        }

        for(int i = 1; i <= 500; i++)
            bus[i] += bus[i - 1];
        
        cin >> p;

        cout << "Case #" << i << ':';
        while(p--) {
            cin >> c;
            cout << ' ' << bus[c];
        }
        cout << '\n';
    }
    return 0;
}