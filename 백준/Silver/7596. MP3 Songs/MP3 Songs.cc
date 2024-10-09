#include <iostream>
#include <queue>
#include <string>

using namespace std;

priority_queue<string, vector<string>, greater<string>> pq;

int main() {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);

    int num;
    string title;

    cin >> num;
    for(int sn = 1; num; sn++) {
        while(getchar() != '\n');
        while(num--) {
            getline(cin, title);
            pq.push(title);
        }

        cout << sn << '\n';
        while(!pq.empty()) {
            cout << pq.top() << '\n';
            pq.pop();
        }
        cin >> num;
    }
    return 0;
}