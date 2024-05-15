#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> run_num;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int digit;
    ll num;
    vector<ll> run_list;

    for(int i = 1; i <= 9; i++) {
        num = i;
        for(int j = 0; j < 17; j++) {
            run_num.push_back(num);
            num = num * 10 + i;
        }
    }
    run_num.push_back(100000000000000000);
    sort(run_num.begin(), run_num.end());

    cin >> tc;
    while(tc--) {
        cin >> digit >> num;
        
        run_list = vector<ll>();
        while(num) {
            for(int i = 0; i < run_num.size(); i++) {
                if(run_num[i] > num) {
                    run_list.push_back(run_num[i - 1]);
                    num -= run_num[i - 1];
                    break;
                }
            }
        }

        cout << run_list.size() << '\n';
        for(auto rn: run_list)
            cout << rn << ' ';
        cout << '\n';
    }
    return 0;
}