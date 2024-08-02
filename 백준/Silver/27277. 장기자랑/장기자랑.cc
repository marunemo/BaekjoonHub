#include <iostream>
#include <algorithm>

using namespace std;

int talent[100000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    int left, right;
    int sum;
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> talent[i];
    sort(talent, talent + n);

    left = 0;
    right = n - 1;
    
    sum = talent[right--];
    for(bool turn = true; left < right; turn = !turn) {
        if(!turn)
            left++;
        else {
            sum += talent[right] - talent[left];
            right--;
        }
    }

    cout << sum << endl;
    return 0;
}