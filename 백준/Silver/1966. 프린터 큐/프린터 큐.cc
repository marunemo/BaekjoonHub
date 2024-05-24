#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int paper, target;
    vector<int> printer;
    vector<int> priority_list;
    int curr_p;
    int index;

    cin >> tc;
    while(tc--) {
        cin >> paper >> target;

        printer = vector<int>(paper);
        priority_list = vector<int>(10, 0);
        curr_p = 0;
        for(int i = 0; i < paper; i++) {
            cin >> printer[i];

            priority_list[printer[i]]++;
            curr_p = max(curr_p, printer[i]);
        }

        index = 0;
        for(int turn = 1; curr_p; turn++) {
            while(true) {
                if(printer[index] == curr_p) {
                    printer[index] = -1;
                    priority_list[curr_p]--;
                    while(curr_p && !priority_list[curr_p])
                        curr_p--;
                    break;
                }
                index = (index + 1) % paper;
            }

            if(index == target)
                cout << turn << '\n';
        }
    }

    return 0;
}