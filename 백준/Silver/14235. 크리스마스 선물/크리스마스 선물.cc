#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int query_length, query, present;
    priority_queue<int, vector<int>, less<int>> sleigh;

    cin >> query_length;
    while(query_length--) {
        cin >> query;
        if(!query) {
            if(sleigh.empty())
                cout << -1 << '\n';
            else {
                cout << sleigh.top() << '\n';
                sleigh.pop();
            }
        }

        while(query--) {
            cin >> present;
            sleigh.push(present);
        }
    }
    return 0;
}