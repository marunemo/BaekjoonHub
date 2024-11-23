#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, num, sum = 0, max_sum = -1000;

    cin >> n;
    while(n--) {
        cin >> num;

        sum += num;

        max_sum = max(sum, max_sum);
        if(sum < 0)
            sum = 0;
    }
    
    cout << max_sum << endl;
    return 0;
}