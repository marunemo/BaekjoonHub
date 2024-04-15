#include <iostream>
#include <string>

using namespace std;

bool is_palin[2500][2500];
int cnt_palin[2500];

int main() {
    string str;
    int len;
    
    cin >> str;
    len = str.length();

    for(int i = 0; i < len; i++) {
        is_palin[i][i] = true;
        if(i > 0)
            is_palin[i-1][i] = (str[i-1] == str[i]);
    }

    for(int end = 0; end < len; end++) {
        for(int start = end - 1; start >= 0; start--) {
            if(start <= end - 2)
                is_palin[start][end] = (is_palin[start + 1][end - 1] & str[start] == str[end]);
        }
    }

    cnt_palin[0] = 1;
    for(int i = 1; i < len; i++) {
        cnt_palin[i] = cnt_palin[i - 1] + 1;
        for(int j = i - 1; j >= 0; j--) {
            if(is_palin[j][i]) {
                if(j == 0)
                    cnt_palin[i] = 1;
                else
                    cnt_palin[i] = min(cnt_palin[i], cnt_palin[j - 1] + 1);
            }
        }
    }

    cout << cnt_palin[len - 1] << endl;
    return 0;
}