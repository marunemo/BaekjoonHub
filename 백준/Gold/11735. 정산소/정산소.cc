#include <iostream>

using namespace std;
using ll = long long;

int n, q;
char dir;
int num;
ll sum, r_offset, c_offset;
int r_count, c_count;
bool r_contain[1000001], c_contain[1000001];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    while(q--) {
        cin >> dir >> num;
        
        sum = (ll)num * n + (ll)n * (n + 1) / 2;

        if(dir == 'R') {
            if(r_contain[num])
                sum = 0;
            else {
                sum -= (ll)num * c_count + c_offset;

                r_offset += num;
                r_count++;
                r_contain[num] = true;
            }
        }
        else {
            if(c_contain[num])
                sum = 0;
            else {
                sum -= (ll)num * r_count + r_offset;

                c_offset += num;
                c_count++;
                c_contain[num] = true;
            }
        }

        cout << sum << '\n';
    }
    return 0;
}