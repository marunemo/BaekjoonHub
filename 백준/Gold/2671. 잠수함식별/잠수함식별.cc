#include <iostream>
#include <string>

using namespace std;

bool set1[150] = {false};

int main() {
    string pattern;
    int len;
    bool flag = true;
    
    cin >> pattern;
    len = pattern.length();

    for(int i = 2; i < len; i++) {
        if(pattern[i - 2] == '1' && pattern[i - 1] == '0' && pattern[i] == '0')
            set1[i - 2] = true;
    }

    for(int i = 0; i < len && flag; i++) {
        if(!set1[i]) {
            if(i + 1 == len)
                flag = false;
            else if(pattern[i] == '0' && pattern[i + 1] == '1')
                i++;
            else
                flag = false;
        }
        else {
            for(i++; i < len && pattern[i] == '0'; i++);
            if(i == len) {
                flag = false;
                break;
            }

            for(i++; i < len && pattern[i] == '1' && !set1[i]; i++);
            i--;
        }
    }

    if(flag)
        cout << "SUBMARINE" << endl;
    else
        cout << "NOISE" << endl;
    return 0;
}