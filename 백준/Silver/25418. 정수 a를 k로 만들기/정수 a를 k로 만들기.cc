#include <iostream>
#include <queue>

using namespace std;

bool check[1000001];
queue<int> Q;

int main() {
    int a, k, size;
    int count;
    bool found;

    cin >> a >> k;
    Q.push(a);
    for(count = 0, found = false; !found; count += !found) {
        size = Q.size();
        for(int i = 0; i < size && !found; i++) {
            a = Q.front();
            Q.pop();

            if(a == k)
                found = true;
            else {
                if(a + 1 <= k && !check[a + 1]) {
                    check[a + 1] = true;
                    Q.push(a + 1);
                }
                if(a * 2 <= k && !check[a * 2]) {
                    check[a * 2] = true;
                    Q.push(a * 2);
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}