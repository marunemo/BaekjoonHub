#include <iostream>

using namespace std;

int n;
int light[200000];
bool turn[200000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int sum_light = 0;
    int extra_light = 0;
    int max_light = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> light[i];
    for(int i = 0; i < n; i++)
        cin >> turn[i];

    sum_light = 0;
    for(int i = 0; i < n; i++)
        sum_light += turn[i] * light[i];

    extra_light = 0;
    for(int i = 0; i < n; i++) {
        extra_light += (1 - 2 * turn[i]) * light[i];
        max_light = max(max_light, sum_light + extra_light);
        extra_light = max(extra_light, 0);
    }

    cout << max_light << endl;
    return 0;
}