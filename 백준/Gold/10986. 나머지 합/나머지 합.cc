#include <iostream>

using namespace std;
using ll = long long;

ll CaseCount(ll num) {
    if(num <= 1)
        return 0;
    return num * (num - 1) / 2;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    ll num_count, mod;
    ll num;
    ll prefix_sum = 0;
    ll sum_count[1000] = {0};
    ll sec_count = 0;
    
    cin >> num_count >> mod;
    for(int i = 0; i < num_count; i++) {
        cin >> num;
        prefix_sum = (prefix_sum + num) % mod;
        sum_count[prefix_sum]++;
        // i=j일 때 나누어 떨어지는 경우
        if(prefix_sum == 0)
            sec_count++;
    }

    // i<j일 때 나누어 떨어지는 경우
    for(int i = 0; i < mod; i++)
        sec_count += CaseCount(sum_count[i]);
    
    cout << sec_count << endl;
    return 0;
}