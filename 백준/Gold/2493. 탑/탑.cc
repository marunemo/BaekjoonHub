#include <iostream>
#include <stack>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tower_count, height;
    stack<pii> tower;
    int tower_index;

    cin >> tower_count;
    for(int i = 1; i <= tower_count; i++) {
        cin >> height;

        while(!tower.empty() && tower.top().first < height) {
            tower.pop();
        }

        tower_index = 0;
        if(!tower.empty()) tower_index = tower.top().second;
        
        cout << tower_index << ' ';
        
        tower.push({height, i});
    }

    cout << endl;
    return 0;
}