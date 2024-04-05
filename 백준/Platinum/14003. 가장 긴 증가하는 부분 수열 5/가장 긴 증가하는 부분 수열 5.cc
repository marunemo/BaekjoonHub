#include <iostream>
#include <vector>

using namespace std;

long permut[1000000];
long lis[1000000];
int memo[1000000];

int main() {
    // Fast IO
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int index = 0;
    for(int i = 0; i < n; i++) {
        cin >> permut[i];

        if(index == 0) {
            lis[index] = permut[i];
            memo[i] = index;
            index++;
        }
        else {
            if(lis[index - 1] < permut[i]) {
                lis[index] = permut[i];
                memo[i] = index;
                index++;
            }
            else {
                int l = 0;
                int r = index - 1;
                int mid;
                while(l < r) {
                    mid = (l + r) / 2;
                    if(lis[mid] < permut[i])
                        l = mid + 1;
                    else
                        r = mid;
                }
                lis[r] = permut[i];
                memo[i] = r;
            }
        }
    }

    cout << index << '\n';
    vector<long> order;
    for(int i = n - 1; i >= 0; i--) {
        if(memo[i] == index - 1) {
            order.push_back(permut[i]);
            index--;
        }
    }
    
    while(!order.empty()) {
        cout << order.back() << ' ';
        order.pop_back();
    }
    cout << endl;
    return 0;
}