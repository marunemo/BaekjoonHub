#include <iostream>

using namespace std;

int alcohol[1000000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, l;
    int total_alcohol = 0;
    int due_time = 0;

    cin >> n >> l;
    for(int i = 0; i < l; i++) {
        cin >> alcohol[i];

        total_alcohol += alcohol[i];

        if(total_alcohol >= 129 && total_alcohol <= 138)
            due_time++;
    }

    for(int i = l; i < n; i++) {
        cin >> alcohol[i];

        total_alcohol += alcohol[i];
        total_alcohol -= alcohol[i - l];

        if(total_alcohol >= 129 && total_alcohol <= 138)
            due_time++;
    }

    cout << due_time << endl;
    return 0;
}