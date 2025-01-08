#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, dir;
    int left = 0, right = 0;
    int max_score = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> dir;

        if(dir == 1) {
            left++;
            if(right)
                right--;
            max_score = max(max_score, left);
        }
        else if(dir == 2) {
            if(left)
                left--;
            right++;
            max_score = max(max_score, right);
        }
    }
    cout << max_score << endl;
    return 0;
}