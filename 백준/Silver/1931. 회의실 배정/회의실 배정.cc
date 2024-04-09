#include <iostream>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int schedule_count;
pii schedule[100000];

bool Compare(pii a, pii b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int end_time = 0;
    int max_count = 0;

    cin >> schedule_count;
    for(int i = 0; i < schedule_count; i++)
        cin >> schedule[i].first >> schedule[i].second;
    sort(schedule, schedule + schedule_count, Compare);

    for(int i = 0; i < schedule_count; i++) {
        if(schedule[i].first >= end_time) {
            max_count++;
            end_time = schedule[i].second;
        }
    }

    cout << max_count << endl;
    return 0;
}