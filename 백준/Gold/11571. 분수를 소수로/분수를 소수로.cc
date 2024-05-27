#include <iostream>
#include <string>

using namespace std;

int memo[10241];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int a, b;
    string cycle;
    int index;

    cin >> tc;
    while(tc--) {
        cin >> a >> b;

        cout << (a / b) << '.';
        a %= b;
        a *= 10;

        for(int i = 0; i <= 10240; i++)
            memo[i] = 0;
        cycle = "";
        index = 0;
        while(a && !memo[a]) {
            memo[a] = ++index;
            cycle += '0' + (a / b);
            a %= b;
            a *= 10;
        }

        if(a == 0)
            cout << cycle << "(0)";
        else {
            for(int i = 0; i < memo[a] - 1; i++)
                cout << cycle[i];
            cout << '(';
            for(int i = memo[a] - 1; i < cycle.length(); i++)
                cout << cycle[i];
            cout << ')';
        }
        cout << '\n';
    }
    return 0;
}