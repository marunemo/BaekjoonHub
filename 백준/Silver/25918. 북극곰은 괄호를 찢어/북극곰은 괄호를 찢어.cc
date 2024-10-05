#include <iostream>
#include <stack>

using namespace std;

int main() {
    int len;
    char *str;
    stack<char> parenthesis;
    int max_len = 0;

    cin >> len;
    
    str = new char[len + 1];
    cin >> str;

    for(int i = 0; i < len; i++) {
        if(parenthesis.empty() || str[i] == parenthesis.top()) {
            parenthesis.push(str[i]);
            max_len = max(max_len, (int)parenthesis.size());
        }
        else
            parenthesis.pop();
    }

    if(!parenthesis.empty())
        cout << -1 << endl;
    else
        cout << max_len << endl;
    delete str;
    return 0;
}