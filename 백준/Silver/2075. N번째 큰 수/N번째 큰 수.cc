#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, num;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num);
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> num;
            pq.push(num);
            pq.pop();
        }
    }

    cout << pq.top() << endl;
    return 0;
}