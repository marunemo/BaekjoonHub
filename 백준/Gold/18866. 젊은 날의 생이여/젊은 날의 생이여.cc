#include <iostream>

using namespace std;
using pii = pair<int, int>;

int date_count;
pii happy_tired[1000000];
int min_happy, max_happy, min_tired, max_tired;
pii young[1000000], old[1000000];
int last_date = -1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> date_count;
    for(int i = 0; i < date_count; i++)
        cin >> happy_tired[i].first >> happy_tired[i].second;

    min_happy = 1e9 + 1;
    max_tired = 0;
    for(int i = 0; i < date_count; i++) {
        if(happy_tired[i].first)
            min_happy = min(min_happy, happy_tired[i].first);
        if(happy_tired[i].second)
            max_tired = max(max_tired, happy_tired[i].second);

        young[i] = {min_happy, max_tired};
    }

    max_happy = 0;
    min_tired = 1e9 + 1;
    for(int i = date_count - 1; i >= 0; i--) {
        if(happy_tired[i].first)
            max_happy = max(max_happy, happy_tired[i].first);
        if(happy_tired[i].second)
            min_tired = min(min_tired, happy_tired[i].second);

        old[i] = {max_happy, min_tired};
    }

    for(int i = 0; i < date_count - 1; i++) {
        if(young[i].first >= old[i + 1].first && young[i].second <= old[i + 1].second)
            last_date = i + 1;
    }

    cout << last_date << endl;
    return 0;
}