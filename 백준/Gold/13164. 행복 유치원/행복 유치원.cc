#include <iostream>
#include <algorithm>

using namespace std;

int child_count, group_count;
int height[300000];
int diff[300000 - 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int diff_sum = 0;

    cin >> child_count >> group_count;
    cin >> height[0];
    for(int i = 1; i < child_count; i++) {
        cin >> height[i];
        diff[i - 1] = height[i] - height[i - 1];
    }
    sort(diff, diff + child_count - 1, greater<int>());

    for(int i = 0; i < group_count - 1; i++)
        diff_sum += diff[i];
    cout << (height[child_count - 1] - height[0] - diff_sum) << endl;
    return 0;
}