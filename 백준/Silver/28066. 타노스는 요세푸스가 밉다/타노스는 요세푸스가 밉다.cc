#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    int key;
    deque<int> dq;

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        dq.push_back(i);
    while(dq.size() != 1) {
        key = dq.front();
        dq.pop_front();
        dq.push_back(key);

        for(int i = 1; i < k && dq.front() != key; i++)
            dq.pop_front();
    }

    cout << dq.front() << endl;
    return 0;
}