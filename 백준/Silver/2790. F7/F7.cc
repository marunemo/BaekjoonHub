#include <iostream>
#include <algorithm>

using namespace std;

int driver[300000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    int max_point = 0;
    int count = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> driver[i];
    sort(driver, driver + n);

    for(int i = 0; i < n; i++)
        max_point = max(max_point, driver[i] + (n - i));
    count += (max_point == driver[0] + n);

    for(int i = 1; i < n; i++) {
        if(driver[i] + n >= max_point) {
            max_point = driver[i] + n;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}