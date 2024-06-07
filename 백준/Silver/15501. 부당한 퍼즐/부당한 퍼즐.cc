#include <iostream>

using namespace std;

int problem[1000000];
int answer[1000000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    int index = -1;
    bool left, right;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> problem[i];
    for(int i = 0; i < n; i++)
        cin >> answer[i];

    for(int i = 0; index == -1; i++) {
        if(problem[0] == answer[i])
            index = i;
    }

    right = true;
    for(int i = 0; i < n && right; i++) {
        if(problem[i] != answer[(index + i) % n])
            right = false;
    }

    left = true;
    for(int i = 0; i < n && left; i++) {
        if(problem[i] != answer[(index - i + n) % n])
            left = false;
    }

    if(left || right)
        cout << "good";
    else
        cout << "bad";
    cout << " puzzle\n";
    return 0;
}