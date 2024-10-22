#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;
    bool lion[1000000];
    int doll;
    int left, right, count;
    int min_len;

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> doll;
        lion[i] = doll == 1;
    }
    
    for(right = 0; right < n && !lion[right]; right++);

    min_len = n + 1;
    left = right;
    count = 1;
    while(right < n) {
        if(left > right)
            right = left;
        else if(count < k) {
            for(right++; right < n && !lion[right]; right++);
            count++;
        }
        else {
            min_len = min(min_len, right - left + 1);
            for(left++; left < right && !lion[left]; left++);
            count--;
        }
    }

    if(min_len == n + 1)
        cout << -1 << endl;
    else
        cout << min_len << endl;
    return 0;
}