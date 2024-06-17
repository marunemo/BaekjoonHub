#include <iostream>

using namespace std;

char str[1001];
int src[26];
int dest[26];

void Clear() { 
    for(int i = 0; i < 26; i++)
        src[i] = dest[i] = 0;
}

bool Strfry() {
    for(int i = 0; i < 26; i++) {
        if(src[i] != dest[i])
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;
    while(tc--) {
        Clear();

        cin >> str;
        for(int i = 0; str[i]; i++)
            src[str[i] - 'a']++;

        cin >> str;
        for(int i = 0; str[i]; i++)
            dest[str[i] - 'a']++;

        if(Strfry())
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}