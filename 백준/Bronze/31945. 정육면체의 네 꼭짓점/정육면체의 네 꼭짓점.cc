#include <iostream>

using namespace std;

const bool FACE[6][8] = {
    {1, 1, 1, 1, 0, 0, 0, 0}, // 0, 1, 2, 3
    {0, 0, 0, 0, 1, 1, 1, 1}, // 4, 5, 6, 7
    {1, 0, 1, 0, 1, 0, 1, 0}, // 0, 2, 4, 6
    {0, 1, 0, 1, 0, 1, 0, 1}, // 1, 3, 5, 7
    {1, 1, 0, 0, 1, 1, 0, 0}, // 0, 1, 4, 5
    {0, 0, 1, 1, 0, 0, 1, 1}  // 2, 3, 6, 7
};

bool Check(bool const vertice[8], int index) {
    for(int i = 0; i < 8; i++) {
        if(vertice[i] != FACE[index][i])
            return false;
    }
    return true;
}

bool IsFace(bool const vertice[8]) {
    for(int i = 0; i < 6; i++) {
        if(Check(vertice, i))
            return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int tc;
    bool vertice[8];
    int p;

    cin >> tc;
    while(tc--) {
        for(int i = 0; i < 8; i++)
            vertice[i] = false;

        for(int i = 0; i < 4; i++) {
            cin >> p;
            vertice[p] = true;
        }

        if(IsFace(vertice))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}