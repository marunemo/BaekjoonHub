#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

priority_queue<ll, vector<ll>, less<ll>> pq;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int giant;
    ll centi;
    int count, limit;
    ll height;

    cin >> giant >> centi >> limit;
    for(int i = 0; i < giant; i++) {
        cin >> height;
        pq.push(height);
    }

    for(count = 0; count < limit && pq.top() != 1 && centi <= pq.top(); count++) {
        pq.push(pq.top() / 2);
        pq.pop();
    }

    if(centi <= pq.top())
        cout << "NO\n" << pq.top() << endl;
    else
        cout << "YES\n" << count << endl;
    return 0;
}