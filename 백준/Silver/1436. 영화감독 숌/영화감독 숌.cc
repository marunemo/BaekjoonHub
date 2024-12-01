#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, num = 0;
    set<int> s;

    cin >> n;

    // ????666 => 10000
    // ???666? => 10000
    // ??666?? => 10000
    // ?666??? => 10000
    // 666???? => 10000
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                for(int l = 0; l < 10; l++) {
                    s.insert((i * 1000 + j * 100 + k * 10 + l) * 1000 + 666);
                    s.insert((i * 1000 + j * 100 + k * 10) * 1000 + 666 * 10 + (l));
                    s.insert((i * 1000 + j * 100) * 1000 + 666 * 100 + (k * 10 + l));
                    s.insert((i * 1000) * 1000 + 666 * 1000 + (j * 100 + k * 10 + l));
                    s.insert(666 * 10000 + (i * 1000 + j * 100 + k * 10 + l));
                }
            }
        }
    }
    
    auto iter = s.begin();
    for(int i = 1; i < n; i++)
        iter++;

    cout << *iter << endl;
    return 0;
}