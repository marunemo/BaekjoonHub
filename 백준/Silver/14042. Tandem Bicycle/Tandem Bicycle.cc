#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int question, n;
    int d[100];
    int p[100];
    int total = 0;

    cin >> question >> n;
    for(int i = 0; i < n; i++)
        cin >> d[i];
    for(int i = 0; i < n; i++)
        cin >> p[i];
    
    sort(p, p + n);
    if(question == 1)
        sort(d, d + n, less<int>());
    else
        sort(d, d + n, greater<int>());
    for(int i = 0; i < n; i++)
        total += max(d[i], p[i]);

    cout << total << endl;
    return 0;    
}