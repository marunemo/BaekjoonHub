#include <iostream>
#include <algorithm>

using namespace std;

struct Date {
    int start_month, start_day, end_month, end_day;
};

int flower_count;
Date date[100000];

bool Compare(Date a, Date b) {
    if(a.start_month != b.start_month)
        return a.start_month < b.start_month;
    if(a.start_day != b.start_day)
        return a.start_day < b.start_day;
    if(a.end_month != b.end_month)
        return a.end_month < b.end_month;
    return a.end_day < b.end_day;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int curr_month = 3;
    int curr_day = 1;
    int next_month = 3;
    int next_day = 1;
    int index, flower = 0;
    bool flag = true;

    cin >> flower_count;
    for(int i = 0; i < flower_count; i++)
        cin >> date[i].start_month >> date[i].start_day >> date[i].end_month >> date[i].end_day;
    sort(date, date + flower_count, Compare);

    
    for(index = 0; index < flower_count && flag && curr_month < 12; ) {
        for(; index < flower_count && (date[index].start_month < curr_month || (date[index].start_month == curr_month && date[index].start_day <= curr_day)); index++) {
            if(next_month < date[index].end_month || (next_month == date[index].end_month && next_day < date[index].end_day)) {
                next_month = date[index].end_month;
                next_day = date[index].end_day;
            }
        }

        if(curr_month == next_month && curr_day == next_day)
            flag = false;
        else {
            // cout << curr_month << ' ' << curr_day << ' ';
            curr_month = next_month;
            curr_day = next_day;
            // cout << curr_month << ' ' << curr_day << '\n';
            flower++;
        }
    }

    if(flag && next_month == 12)
        cout << flower << endl;
    else
        cout << 0 << endl;
    return 0;
}