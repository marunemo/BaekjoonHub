#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

deque<int> idx[101];
int mod_count = 0;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int query_count, mod;
    int query, num;
    int sequence_index = 0;
    int min_index;

    cin >> query_count >> mod;
    while(query_count--) {
        cin >> query;
        if(query == 3) {
            if(mod_count < mod)
                cout << -1 << '\n';
            else {
                min_index = sequence_index;
                for(int i = 0; i < mod; i++)
                    min_index = min(min_index, idx[i].back());
                cout << (sequence_index - min_index) << '\n';
            }
        }
        else if(query == 1) {
            cin >> num;

            num %= mod;
            if(idx[num].empty())
                mod_count++;
            idx[num].push_back(sequence_index++);
        }
        else if(query == 2) {
            sequence_index--;
            for(int i = 0; i < mod; i++) {
                if(!idx[i].empty() && idx[i].back() == sequence_index) {
                    idx[i].pop_back();

                    if(idx[i].empty())
                        mod_count--;

                    break;
                }
            }
        }
    }
    return 0;
}