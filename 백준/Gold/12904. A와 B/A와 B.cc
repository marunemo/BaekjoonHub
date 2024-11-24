#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool Recursion(const string &s, string &t) {
    if(s.length() == t.length())
        return s == t;
    
    if(t.back() == 'A')
        t.pop_back();
    else {
        t.pop_back();
        reverse(t.begin(), t.end());
    }

    return Recursion(s, t);
}

int main() {
    string s, t;

    cin >> s >> t;
    cout << Recursion(s, t) << endl;
    return 0;
}