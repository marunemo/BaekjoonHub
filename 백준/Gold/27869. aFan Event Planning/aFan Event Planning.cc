#include <iostream>
#include <set>

using namespace std;
using ll = long long;

ll event_token[200001];
ll prefix_sum[200001] = {0};
set<int> reset_date;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int date_count, query_count;
    int cmd, start, end, date;

    cin >> date_count >> query_count;
    for(int i = 1; i <= date_count; i++) {
        cin >> event_token[i];
        prefix_sum[i] = prefix_sum[i - 1] + event_token[i];
    }
    for(int i = 0; i < query_count; i++) {
        cin >> cmd;
        if(cmd == 1) {
            cin >> date;
            reset_date.insert(date);
        }
        else if(cmd == 2) {
            cin >> start >> end;

            if(reset_date.empty())
                cout << (prefix_sum[end] - prefix_sum[start - 1]) << '\n';
            else {
                auto iter = reset_date.lower_bound(end);
                if(iter != reset_date.begin())
                    iter--;

                if(*iter < start || *iter >= end)
                    cout << (prefix_sum[end] - prefix_sum[start - 1]) << '\n';
                else
                    cout << (prefix_sum[end] - prefix_sum[*iter]) << '\n';
            }
        }
    }
    return 0;
}