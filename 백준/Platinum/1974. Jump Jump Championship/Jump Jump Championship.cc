#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc, n, trophy;
    int lis[10000];
    int size;
    int index[10000];
    int left, right, mid;
    int order[10000];
    int order_size;

    cin >> tc;
    while(tc--) {
        cin >> n;
        
        size = 0;
        for(int i = 0; i < n; i++) {
            cin >> trophy;

            if(i == 0) {
                index[i] = size;
                lis[size++] = trophy;
            }
            else if(lis[size - 1] < trophy) {
                index[i] = size;
                lis[size++] = trophy;
            }
            else {
                left = 0;
                right = size - 1;
                while(left < right) {
                    mid = (left + right) / 2;
                    if(lis[mid] < trophy)
                        left = mid + 1;
                    else
                        right = mid;
                }
                index[i] = right;
                lis[right] = trophy;
            }
        }

        order_size = 0;
        cout << size-- << '\n';
        for(int i = n - 1; i >= 0; i--) {
            if(index[i] == size) {
                size--;
                order[order_size++] = i + 1;
            }
        }

        for(int i = order_size - 1; i >= 0; i--)
            cout << order[i] << ' ';
        cout << '\n';
    }
    return 0;
}