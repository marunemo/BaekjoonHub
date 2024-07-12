#include <iostream>

using namespace std;

int num[100000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int count, length;
    int window = 0;
    int max_window = 0;

    cin >> count >> length;
    for(int i = 0; i < length; i++) {
        cin >> num[i];
        window += num[i];
    }

    max_window = window;
    for(int i = length; i < count; i++) {
        cin >> num[i];

        window -= num[i - length];
        window += num[i];
        max_window = max(window, max_window);
    }

    cout << max_window << endl;
    return 0;
}