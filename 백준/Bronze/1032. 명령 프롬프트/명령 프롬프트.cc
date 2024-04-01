#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, length;
    string file_name[50];
    bool flag;
    string pattern = "";

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> file_name[i];

    length = file_name[0].length();
    for(int c = 0; c < length; c++) {
        flag = true;
        for(int i = 1; i < n && flag; i++) {
            if(file_name[i][c] != file_name[i - 1][c])
                flag = false;
        }
        if(flag)
            pattern += file_name[0][c];
        else
            pattern += '?';
    }
    cout << pattern << endl;
    return 0;
}