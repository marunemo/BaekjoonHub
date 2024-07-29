#include <iostream>
#include <algorithm>

using namespace std;

int driver[300000];
int point[300000];

int main() {
    int n;
    int max_point = 0;
    int count = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> driver[i];
        point[i] = n - i;
    }
    sort(driver, driver + n);

    for(int i = 0; i < n; i++)
        max_point = max(max_point, driver[i] + point[i]);
    count += (max_point == driver[0] + point[0]);

    for(int i = 1; i < n; i++) {
        point[i] = point[i - 1];
        max_point = max(max_point, driver[i] + point[i]);
        count += (max_point == driver[i] + point[i]);
    }

    cout << count << endl;
    return 0;
}