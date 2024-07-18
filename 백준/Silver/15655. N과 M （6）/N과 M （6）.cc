#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[8];

void DFS(int index, int count, int mask) {
    if(count == m) {
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i))
                cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    if(index == n)
        return;
    
    DFS(index + 1, count + 1, mask | (1 << index));
    DFS(index + 1, count, mask);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);

    DFS(0, 0, 0);

    return 0;
}