#include <iostream>
#include <string>

using namespace std;

int map[10] = {
    31599,
    0,
    29671,
    29647,
    23497,
    31183,
    31215,
    29257,
    31727,
    31695
};

int main() {
    int len;
    string signal;
    string pattern[5];
    bool flag;
    int match;

    cin >> len >> signal;
    for(int index = 0, i = 0; i < len; i += len / 5)
        pattern[index++] = signal.substr(i, len / 5);
    
    len /= 5;
    for(int col = 0; col < len; col++) {
        // empty
        if(pattern[0][col] == '.')
            continue;
        
        // 1
        if(col + 1 == len || col + 2 == len) {
            cout << 1;
            continue;
        }
        
        match = 0;
        for(int r = 0; r < 5; r++) {
            for(int c = 0; c < 3; c++)
                match = (match << 1) | (pattern[r][col + c] == '#');
        }

        flag = false;
        for(int i = 0; i < 10 && !flag; i++) {
            flag = !(match ^ map[i]);
            if(flag)
                cout << i;
        }

        if(flag)
            col += 3;
        else
            cout << 1;
    }

    cout << endl;
    return 0;
}