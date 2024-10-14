#include <iostream>
#include <string>

using namespace std;

int main() {
    string gear1, gear2;
    int len1, len2;
    int min_len;
    bool flag;
    
    cin >> gear1 >> gear2;
    len1 = gear1.length();
    len2 = gear2.length();
    min_len = len1 + len2;

    for(int start = 0; start < len2; start++) {
        flag = true;
        for(int i = start; i < len2 && flag; i++) {
            if(i - start >= len1)
                break;
            flag = (gear1[i - start] != '2') || (gear2[i] != '2');
        }
        
        if(flag)
            min_len = min(min_len, max(start + len1, len2));
    }

    for(int start = 0; start < len1; start++) {
        flag = true;
        for(int i = start; i < len1 && flag; i++) {
            if(i - start >= len2)
                break;
            flag = (gear1[i] != '2') || (gear2[i - start] != '2');
        }
        
        if(flag)
            min_len = min(min_len, max(start + len2, len1));
    }

    cout << min_len << endl;
    return 0;
}