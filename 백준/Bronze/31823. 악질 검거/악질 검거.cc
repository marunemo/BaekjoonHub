#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int people;
    string person;
    int date;
    char stric;
    int stric_len, max_stric;
    vector<pair<int, string>> result;
    unordered_map<int, bool> mask;
    int mask_count = 0;

    cin >> people >> date;
    while(people--) {
        max_stric = 0;
        stric_len = 0;
        for(int i = 0; i < date; i++) {
            cin >> stric;
            if(stric == '*') {
                max_stric = max(max_stric, stric_len);
                stric_len = 0;
            }
            else {
                stric_len++;
            }
        }
        max_stric = max(max_stric, stric_len);

        cin >> person;
        if(!mask[max_stric]) {
            mask[max_stric] = true;
            mask_count++;
        }
        result.push_back({max_stric, person});
    }

    cout << mask_count << '\n';
    for(auto k: result)
        cout << k.first << ' ' << k.second << '\n';
    return 0;
}