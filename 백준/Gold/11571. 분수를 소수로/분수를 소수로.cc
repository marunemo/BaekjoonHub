#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int a, b;
    string result;
    string cycle;
    int index;

    cin >> tc;
    while(tc--) {
        cin >> a >> b;

        result = to_string(a / b) + ".";
        a %= b;
        a *= 10;

        memo.clear();
        cycle = "";
        index = 0;
        while(a && !memo[a]) {
            memo[a] = ++index;
            cycle += '0' + (a / b);
            a %= b;
            a *= 10;
        }

        if(a == 0)
            result += cycle + "(0)";
        else
            result += cycle.substr(0, memo[a] - 1) + "(" + cycle.substr(memo[a] - 1, cycle.length()) + ")";
        cout << result << '\n';
    }
    return 0;
}