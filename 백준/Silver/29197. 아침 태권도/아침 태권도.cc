#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, unordered_map<int, bool>> check;

int GCD(int a, int b) {
    if(b == 0)
        return a;
    return GCD(b, a % b);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, x, y, gcd;
    int count = 0;

    cin >> n;
    while(n--) {
        cin >> x >> y;
        gcd = GCD(abs(x), abs(y));
        
        x /= gcd;
        y /= gcd;

        if(!check[x][y]) {
            check[x][y] = true;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}