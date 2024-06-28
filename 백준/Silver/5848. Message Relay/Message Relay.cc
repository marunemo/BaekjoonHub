#include <iostream>

using namespace std;

int f[1001];
bool visit[1001];

bool Loopy(int cow) {
    if(cow == 0)
        return false;
    
    if(visit[cow])
        return true;
    visit[cow] = true;
    
    return Loopy(f[cow]);
}

int main() {
    int n;
    int count = 0;

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> f[i];
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            visit[j] = false;

        if(!Loopy(i))
            count++;
    }
    
    cout << count << endl;
    return 0;
}