#include <iostream>

using namespace std;

/**
 * 1 → 2로 n-1개 이동
 * 1 → 3으로 마지막 원판 이동
 * -----
 * 2 → 1로 n-1개 이동
 * 2 → 3으로 마지막 원판 이동
 */

void move(int from, int to) { 
    cout << from << ' ' << to << '\n'; 
}

void hanoi(int n, int from = 1, int by = 2, int to = 3) { 
    if(n == 0)
        return;

    hanoi(n - 1, from, to, by); 
    move(from, to); 
    hanoi(n - 1, by, from, to); 
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;

    cin >> n;
    cout << ((1 << n) - 1) << '\n';
    hanoi(n);
    return 0;
}