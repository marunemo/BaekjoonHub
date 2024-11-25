#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
using pli = pair<ll, int>;

bool Compare(pli a, pli b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

pli ice_cream[100000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int total, ate;
    int left, right;
    bool flip = false;
    
    cin >> total >> ate;
    for(int i = 0; i < total; i++) {
        cin >> ice_cream[i].first;
        ice_cream[i].second = i + 1;
    }
    sort(ice_cream, ice_cream + total, Compare);

    for(int i = 0; i < ate; ) {
        left = i;
        right = i;

        while(ice_cream[left].first == ice_cream[right + 1].first)
            right++;
        
        for(; i < ate && left <= right; i++) {
            if(flip)
                cout << ice_cream[right--].second << '\n';
            else
                cout << ice_cream[left++].second << '\n';
            
            if(ice_cream[i].first % 7 == 0)
                flip = !flip;
        }
    }
    
    return 0;
}