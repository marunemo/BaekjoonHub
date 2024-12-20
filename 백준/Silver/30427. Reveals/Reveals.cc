#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string init;
    int candidate_count;
    string candidate[1000];
    int swi = -1;
    int detect_count;
    string detect;
    unordered_map<string, int> pointed;
    bool dongho = false, bumin = false, cake = false, lawyer = false;
    int none_count, none_index[1000];
    int suspect;

    getline(cin, init);
    cin >> candidate_count;
    for(int i = 0; i < candidate_count; i++) {
        cin >> candidate[i];
        if(candidate[i] == "dongho")
            dongho = true;
        else if(candidate[i] == "swi")
            swi = i;
    }
    cin >> detect_count;
    for(int i = 0; i < detect_count; i++) {
        cin >> detect;
        pointed[detect]++;
    }

    // swi가 아닌 N명
    if(swi != -1)
        candidate[swi] = candidate[--candidate_count];

    // 1번 조건
    if(dongho) {
        cout << "dongho" << endl;
        return 0;
    }

    none_count = 0;
    for(int i = 0; i < candidate_count; i++) {
        if(!pointed[candidate[i]]) {
            none_index[none_count++] = i;
            if(candidate[i] == "bumin")
                bumin = true;
            else if(candidate[i] == "cake")
                cake = true;
            else if(candidate[i] == "lawyer")
                lawyer = true;
        }
    }
    
    // hidden: 7번 조건
    if(!none_count) {
        cout << "swi" << endl;
        return 0;
    }

    // 2번 조건
    if(none_count == 1) {
        cout << candidate[none_index[0]] << endl;
        return 0;
    }

    // 3번 조건
    if(bumin) {
        cout << "bumin" << endl;
        return 0;
    }

    // 4번 조건
    if(cake) {
        cout << "cake" << endl;
        return 0;
    }

    // 5번 조건
    if(lawyer) {
        cout << "lawyer" << endl;
        return 0;
    }

    // 6번 조건
    suspect = 0;
    for(int i = 1; i < none_count; i++) {
        if(candidate[none_index[suspect]] > candidate[none_index[i]])
            suspect = i;
    }
    cout << candidate[none_index[suspect]] << endl;
    return 0;
}