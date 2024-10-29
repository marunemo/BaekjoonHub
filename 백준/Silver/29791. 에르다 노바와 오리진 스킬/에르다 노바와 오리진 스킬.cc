#include <iostream>
#include <algorithm>

using namespace std;

int e_keystroke[1000000];
int o_keystroke[1000000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    int cooldown, count;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> e_keystroke[i];
    sort(e_keystroke, e_keystroke + n);
    
    for(int i = 0; i < m; i++)
        cin >> o_keystroke[i];
    sort(o_keystroke, o_keystroke + m);

    cooldown = count = 0;
    for(int i = 0; i < n; i++) {
        if(cooldown <= e_keystroke[i]) {
            cooldown = e_keystroke[i] + 100;
            count++;
        }
    }
    cout << count << ' ';

    cooldown = count = 0;
    for(int i = 0; i < m; i++) {
        if(cooldown <= o_keystroke[i]) {
            cooldown = o_keystroke[i] + 360;
            count++;
        }
    }
    cout << count << endl;

    return 0;
}