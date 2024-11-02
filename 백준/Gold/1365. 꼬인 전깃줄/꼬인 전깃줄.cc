#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, num;
    int lis[100000], index = 0;
    int left, right, mid;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        
        if(index == 0 || lis[index - 1] < num)
            lis[index++] = num;
        else {
            left = 0;
            right = index - 1;
            while(left < right) {
                mid = (left + right) / 2;
                if(lis[mid] < num)
                    left = mid + 1;
                else
                    right = mid;
            }
            lis[right] = num;
        }
    }
    cout << (n - index) << endl;
    return 0;
}