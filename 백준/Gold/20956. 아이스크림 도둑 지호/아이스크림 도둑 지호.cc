#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int total, ate;
    vector<ll> ice_cream;
    unordered_map<ll, deque<int>> index;
    bool flip = false;

    cin >> total >> ate;
    ice_cream.resize(total);
    for(int i = 0; i < total; i++) {
        cin >> ice_cream[i];
        index[ice_cream[i]].push_back(i + 1);
    }
    sort(ice_cream.begin(), ice_cream.end(), greater<ll>());

    for(int i = 0; i < ate; i++) {
        if(flip) {
            cout << index[ice_cream[i]].back() << '\n';
            index[ice_cream[i]].pop_back();
        }
        else {
            cout << index[ice_cream[i]].front() << '\n';
            index[ice_cream[i]].pop_front();
        }

        if(ice_cream[i] % 7 == 0)
            flip = !flip;
    }
    return 0;
}