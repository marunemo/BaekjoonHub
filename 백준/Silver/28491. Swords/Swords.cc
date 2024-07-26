#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

struct Compare {
    bool operator()(pii a, pii b) {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};

pii sword[100000];
priority_queue<pii, vector<pii>, Compare> pq;

int main() {
    int n;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> sword[i].first >> sword[i].second;
    sort(sword, sword + n);

    for(int i = 0; i < n; i++) {
        while(!pq.empty() && pq.top().first <= sword[i].first && pq.top().second <= sword[i].second)
            pq.pop();
        pq.push(sword[i]);
    }

    cout << pq.size() << endl;
    return 0;
}