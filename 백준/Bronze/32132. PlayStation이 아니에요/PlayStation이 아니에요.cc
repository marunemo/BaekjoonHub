#include <iostream>

using namespace std;

int main() {
    int len;
    char str[51];

    cin >> len >> str;
    for(int index, i = 0; i < len; i++) {
        cout << str[i];
        if(i > 0 && str[i - 1] == 'P' && str[i] == 'S') {
            index = i + 1;
            while(index < len && (str[index] == '4' || str[index] == '5'))
                index++;
            i = index - 1;
        }
    }
    cout << endl;
    return 0;
}