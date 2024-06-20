#include <iostream>
#include <stack>

using namespace std;

stack<char> parenthesis;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    char str[51];
    bool flag;

    cin >> tc;
    while(tc--) {
        cin >> str;

        while(!parenthesis.empty())
            parenthesis.pop();

        flag = true;
        for(int i = 0; str[i]; i++) {
            if(str[i] == '(')
                parenthesis.push('(');
            else if(!parenthesis.empty())
                parenthesis.pop();
            else {
                flag = false;
                break;
            }
        }

        if(!flag || !parenthesis.empty())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}