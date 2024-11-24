#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool Recursion(const string &s, string t) {
    if(s.length() == t.length())
        return s == t;
    
    string t_a;
    bool flag_a = false, flag_b = false;

    if(t.back() == 'A') {
        t_a = t;
        t_a.pop_back();
        flag_a = Recursion(s, t_a);
    }

    if(t[0] == 'B') {
        reverse(t.begin(), t.end());
        t.pop_back();
        flag_b = Recursion(s, t);
    }

    return flag_a | flag_b;
}

int main() {
    string s, t;

    cin >> s >> t;
    cout << Recursion(s, t) << endl;
    return 0;
}