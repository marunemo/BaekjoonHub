#include <iostream>
#include <string>
#include <set>

using namespace std;

string card[10];
set<string> S;

void DFS(const int &n, const int &k, int mask, int pick, string str) {
    if(pick == k) {
        S.insert(str);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!(mask & (1 << i)))
            DFS(n, k, mask | (1 << i), pick + 1, str + card[i]);
    }
}

int main() {
    int n, k;

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> card[i];
    
    DFS(n, k, 0, 0, "");
    cout << S.size() << endl;
    return 0;
}