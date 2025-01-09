#include <iostream>

using namespace std;

int arr[1000000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    int left, right;
    int max_len = -1;

    cin >> n;
    cin >> arr[0];
    for(int i = 1; i < n; i++) {
        cin >> arr[i];

        if(arr[i - 1] > arr[i]) {
            if(left == -1 && right == -1) {
                left = i - 2;
                right = i;
            }
            else {
                left--;
                right++;
            }

            if(left < 0 || right >= n)
                left = right = -1;
            else if(arr[left] != arr[right])
                left = right = -1;
            else
                max_len = max(max_len, right - left + 1);
        }
        else {
            left = right = -1;
        }
    }
    cout << max_len << endl;
    return 0;
}