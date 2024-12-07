#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc, size;
    string phone[10000];
    bool flag;

    cin >> tc;
    while(tc--) {
        cin >> size;
        for(int i = 0; i < size; i++)
            cin >> phone[i];
        sort(phone, phone + size);

        flag = true;
        for(int i = 1; i < size && flag; i++) {
            if(phone[i - 1].length() > phone[i].length())
                continue;
            
            flag = phone[i - 1] != phone[i].substr(0, phone[i - 1].length());
        }

        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}