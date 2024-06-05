#include <iostream>

using namespace std;

int main() {
    int x, y, m;
    int milk = 0;

    cin >> x >> y >> m;
    for(int i = 0; i <= m; i += x) {
        for(int j = 0; i + j <= m; j += y)
            milk = max(milk, i + j);
    }

    cout << milk << endl;
    return 0;
}