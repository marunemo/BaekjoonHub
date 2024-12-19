#include <iostream>
#include <stack>

using namespace std;
using Score = pair<int, int>;

// left happy: min -> just min
// right happy: max -> desc
// left tired: max -> just max
// right happ: min -> asc

int date_count;
Score happy_tired[1000000];
int left_happy, left_tired;
stack<Score> right_happy, right_tired;
int curr_date, last_date = -1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> date_count;
    for(int i = 0; i < date_count; i++)
        cin >> happy_tired[i].first >> happy_tired[i].second;
    
    right_happy.push({0, date_count});
    right_tired.push({1e9, date_count});
    for(int i = date_count - 1; i; i--) {
        if(happy_tired[i].first && happy_tired[i].first > right_happy.top().first)
            right_happy.push({happy_tired[i].first, i});
        if(happy_tired[i].second && happy_tired[i].second < right_tired.top().first)
            right_tired.push({happy_tired[i].second, i});
    }

    curr_date = 0;
    left_happy = 1e9;
    left_tired = 0;

    for(; curr_date < date_count - 1; curr_date++) {
        // update happy
        if(right_happy.top().second <= curr_date)
            right_happy.pop();
        if(happy_tired[curr_date].first)
            left_happy = min(left_happy, happy_tired[curr_date].first);

        // update tired
        if(right_tired.top().second <= curr_date)
            right_tired.pop();
        if(happy_tired[curr_date].second)
            left_tired = max(left_tired, happy_tired[curr_date].second);

        if(left_happy > right_happy.top().first && left_tired < right_tired.top().first)
            last_date = curr_date + 1;
    }

    cout << last_date << endl;
    return 0;
}