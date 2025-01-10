#include <iostream>
#include <algorithm>

using namespace std;

int alice[50001], bob[50001];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int problem, a, b, idx;
    int a_idx, b_idx;
    bool is_alice[2] = {true, false};
    int count[2] = {0, 0};

    cin >> problem >> a >> b;
    for(int i = 0; i < a; i++)
        cin >> alice[i];
    alice[a] = 1e9 + 1;
    for(int i = 0; i < b; i++)
        cin >> bob[i];
    bob[b] = 1e9 + 1;

    sort(alice, alice + a);
    sort(bob, bob + b);
    
    a_idx = b_idx = 0;
    idx = min(alice[a_idx], bob[b_idx]);
    while(idx <= problem) {
        for(int i = 0; i < 2; i++) {
            if(is_alice[i] && alice[a_idx] != idx && bob[b_idx] == idx) {
                count[i]++;
                is_alice[i] = false;
            }
            else if(!is_alice[i] && alice[a_idx] == idx && bob[b_idx] != idx) {
                count[i]++;
                is_alice[i] = true;
            }
        }

        if(a_idx <= a && alice[a_idx] == idx)
            a_idx++;
        if(b_idx <= b && bob[b_idx] == idx)
            b_idx++;
        idx = min(alice[a_idx], bob[b_idx]);
    }

    cout << min(count[0], count[1]) << endl;
    return 0;
}