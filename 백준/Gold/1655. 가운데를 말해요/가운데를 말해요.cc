#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, mid, input;
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;

    cin >> n >> mid;
    cout << mid << '\n';
    
    for(int i = 1; i < n; i++) {
        cin >> input;
        if(input < mid)
            left.push(input);
        else
            right.push(input);
        
        if(left.size() > right.size()) {
            right.push(mid);
            mid = left.top();
            left.pop();
        }
        else if(right.size() > left.size() + 1) {
            left.push(mid);
            mid = right.top();
            right.pop();
        }

        cout << mid << '\n';
    }
    return 0;
}