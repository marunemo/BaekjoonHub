#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int count[12];
    int tc;
    int num;

    count[1] = 1;
    count[2] = 2;
    count[3] = 4;
    for(int n = 4; n <= 11; n++)
        count[n] = count[n - 1] + count[n - 2] + count[n - 3];
    
    cin >> tc;
    while(tc--) {
        cin >> num;
        cout << count[num] << '\n';
    }
    return 0;
}