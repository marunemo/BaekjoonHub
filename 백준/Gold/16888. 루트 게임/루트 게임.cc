#include <iostream>

using namespace std;

bool victory[1000001] = {false};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i <= 1000000; i++) {
        if(victory[i])
            continue;

        for(int j = 1; i + j * j <= 1000000; j++)
            victory[i + j * j] = true;
    }
    
    int tc, num;
    
    cin >> tc;
    while(tc--) {
        cin >> num;

        if(victory[num])
            cout << "koosaga\n";
        else
            cout << "cubelover\n";
    }

    return 0;
}