#include <iostream>
#include <string>

using namespace std;

int ToInteger(string num) {
    int result = 0;
    for(char digit: num)
        result = result * 10 + (digit - '0');
    return result;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int row = 100, col = 100;
    int max_num = 0;
    string result;

    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            cout << "? " << i << ' ' << j << endl;
            cin >> result;
            if(result == "ArrayIndexOutOfBoundsException")
                col = j - 1;
            else
                max_num = max(max_num, ToInteger(result));
        }
    }

    cout << "! " << max_num << endl;
    return 0;
}