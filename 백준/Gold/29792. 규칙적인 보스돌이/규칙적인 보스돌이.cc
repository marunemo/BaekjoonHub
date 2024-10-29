#include <iostream>
#include <algorithm>
#define MAX 15 * 60

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int char_count, limit, mob_count;
ll dps[49];
pll mob[13];
ll meso[MAX + 1];
ll taken, max_meso = 0;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> char_count >> limit >> mob_count;
    for(int i = 0; i < char_count; i++)
        cin >> dps[i];
    sort(dps, dps + char_count, greater<ll>());

    for(int i = 0; i < mob_count; i++)
        cin >> mob[i].first >> mob[i].second;
    
    for(int chosen_c = 0; chosen_c < limit; chosen_c++) {
        for(int time = 0; time <= MAX; time++)
            meso[time] = 0;
        
        for(int chosen_m = 0; chosen_m < mob_count; chosen_m++) {
            taken = (mob[chosen_m].first + dps[chosen_c] - 1) / dps[chosen_c];
            
            for(int time = MAX; time >= taken; time--)
                meso[time] = max(meso[time], meso[time - taken] + mob[chosen_m].second);
        }
        max_meso += meso[MAX];
    }
    cout << max_meso << endl;
    return 0;
}