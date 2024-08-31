#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    int book;
    int lis[200000];
    int index = 0;
    int left, right, mid;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> book;
        if(index == 0)
            lis[index++] = book;
        else if(lis[index - 1] < book)
            lis[index++] = book;
        else {
            left = 0;
            right = index - 1;
            while(left < right) {
                mid = (left + right) / 2;
                if(lis[mid] <= book)
                    left = mid + 1;
                else
                    right = mid;
            }
            lis[right] = book;
        }
    }

    cout << n - index << endl;
    return 0;
}