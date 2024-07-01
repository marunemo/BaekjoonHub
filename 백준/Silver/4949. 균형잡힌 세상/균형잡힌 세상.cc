#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    stack<char> parenthesis;
    string sentence;
    bool balance;

    getline(cin, sentence);
    while(sentence != ".") {
        balance = true;
        parenthesis = stack<char>();

        for(int i = 0; i < sentence.length() && balance; i++) {
            if(sentence[i] == '(' || sentence[i] == '[')
                parenthesis.push(sentence[i]);
            else if(sentence[i] == ']') {
                if(parenthesis.empty())
                    balance = false;
                else if(parenthesis.top() == '(')
                    balance = false;
                else if(parenthesis.top() == '[')
                    parenthesis.pop();
            }
            else if(sentence[i] == ')') {
                if(parenthesis.empty())
                    balance = false;
                else if(parenthesis.top() == '[')
                    balance = false;
                else if(parenthesis.top() == '(')
                    parenthesis.pop();
            }
        }

        if(balance && parenthesis.empty())
            cout << "yes\n";
        else
            cout << "no\n";

        getline(cin, sentence);
    }

    return 0;
}