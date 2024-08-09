#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc, expect, real;
    string prefix;

    cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cin >> expect >> real;

        prefix = "";
        if(expect <= real)
            prefix = "no ";

        for(real *= 5; expect > real; real *= 5)
            prefix += "mega ";

        cout << "Data Set " << i << ":\n";
        cout << prefix << "drought" << "\n\n";
    }
    return 0;
}