#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, char> replaced;

void Replace(char src, char dest) {
    for(int i = 0; i < 26; i++) {
        if(replaced['a' + i] == src)
            replaced['a' + i] = dest;
        if(replaced['A' + i] == src)
            replaced['A' + i] = dest;
    }
}

int MaxLen(char *str) {
    int len = 0, max_len = 0;
    char prev = 0;
    
    for(int i = 0; str[i]; i++) {
        if(prev == replaced[str[i]])
            len++;
        else {
            max_len = max(len, max_len);
            len = 1;
        }
        prev = replaced[str[i]];
    }
    max_len = max(len, max_len);
    return max_len;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    char str[300001];
    int n, query;
    char src, dest;

    for(int i = 0; i < 26; i++) {
        replaced['a' + i] = 'a' + i;
        replaced['A' + i] = 'A' + i;
    }

    cin >> str >> n;
    for(int i = 0; i < n; i++) {
        cin >> query;

        if(query == 1) {
            cin >> src >> dest;
            Replace(src, dest);
        }
        else if(query == 2) {
            cout << MaxLen(str) << '\n';
        }
    }
    return 0;
}