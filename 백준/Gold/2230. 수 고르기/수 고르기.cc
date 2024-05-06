#include <iostream>
#include <algorithm>
#define INF 10000000000

using namespace std;
using ll = long long;

ll seq[100000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int size;
    ll threshold;
    int left, right;
    ll min_diff = INF;
    
    cin >> size >> threshold;
    for(int i = 0; i < size; i++)
        cin >> seq[i];
    sort(seq, seq + size);

    left = 0;
    right = 0;
    while(right < size) {
        if(left == right)
            right++;
        else if(seq[right] - seq[left] < threshold)
            right++;
        else if(seq[right] - seq[left] >= threshold) {
            min_diff = min(min_diff, seq[right] - seq[left]);
            left++;
        }
    }

    cout << min_diff << endl;
    return 0;
}