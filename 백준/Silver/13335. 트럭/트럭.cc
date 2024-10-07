#include <iostream>

using namespace std;

int truck[1000];
int left_time[1000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int truck_count, due_time, limit;
    int left, right, weight;
    int total_time;

    cin >> truck_count >> due_time >> limit;
    for(int i = 0; i < truck_count; i++)
        cin >> truck[i];
    
    left = 0;
    right = 0;
    weight = truck[right];
    left_time[right] = 1 + due_time;
    for(total_time = 1; left < truck_count; total_time++) {
        if(left_time[left] <= total_time) {
            weight -= truck[left];
            left++;
        }

        if(right < truck_count && weight + truck[right + 1] <= limit) {
            right++;
            left_time[right] = total_time + due_time;
            weight += truck[right];
        }
    }
    cout << (total_time - 1) << endl;
    return 0;
}