#include <iostream>
#include <string>

using namespace std;

void DFS(int const &range, int* mask, int const &height, int depth, string result) {
    if(depth == height) {
        cout << result << '\n';
        return;
    }

    for(int i = 1; i <= range; i++) {
        if(!mask[i]) {
            mask[i] = true;
            DFS(range, mask, height, depth + 1, result + to_string(i) + ' ');
            mask[i] = false;
        }
    }
}

int main() {
    int n, m;
    int mask[9] = {0};

    cin >> n >> m;
    
    DFS(n, mask, m, 0, "");
    return 0;
}