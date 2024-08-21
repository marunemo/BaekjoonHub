#include <iostream>

using namespace std;
using ll = long long;

ll n, q;
char dir;
ll num, sum;
ll r_offset = 0, r_count = 0;
bool r_contain[1000001];
ll c_offset = 0, c_count = 0;
bool c_contain[1000001];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> n >> q;
    while(q--) {
        cin >> dir >> num;
        
        // 행/열에서 누적으로 합해지는 부분 + 증가하는 부분
        sum = num * n + n * (n + 1) / 2;

        if(dir == 'R') {
            if(r_contain[num])
                sum = 0;
            else {
                sum -= num * c_count + c_offset;

                r_offset += num;
                r_count++;
                r_contain[num] = true;
            }
        }
        else {
            if(c_contain[num])
                sum = 0;
            else {
                sum -= num * r_count + r_offset;

                c_offset += num;
                c_count++;
                c_contain[num] = true;
            }
        }

        cout << sum << '\n';
    }
    return 0;
}