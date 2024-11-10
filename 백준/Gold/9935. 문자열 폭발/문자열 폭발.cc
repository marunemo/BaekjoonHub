#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string str, explode, rev_explode, ans;
    stack<char> S, tmp;
    int len;
    bool flag;

    cin >> str >> explode;
    
    rev_explode = "";
    for(char c: explode)
        rev_explode = c + rev_explode;
    
    len = rev_explode.length();
    for(char c: str) {
        S.push(c);

        if(S.size() >= len && S.top() == rev_explode[0]) {
            tmp = stack<char>();

            flag = true;
            for(int i = 0; i < len && flag; i++) {
                if(S.empty())
                    flag = false;
                else if(S.top() != rev_explode[i])
                    flag = false;
                else {
                    tmp.push(S.top());
                    S.pop();
                }
            }

            if(flag)
                continue;

            while(!tmp.empty()) {
                S.push(tmp.top());
                tmp.pop();
            }
        }
    }

    if(S.empty())
        str = "FRULA";
    else {
        str = "";
        str.reserve(1000000);
        while(!S.empty()) {
            str.push_back(S.top());
            S.pop();
        }
        reverse(str.begin(), str.end());
    }
    cout << str << endl;
    return 0;
}