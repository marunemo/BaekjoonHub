#include <iostream>
#include <string>

using namespace std;

int count[9];

int main() {
    string num;
    int max_set = 0;

    cin >> num;
    for(char digit: num) {
        if(digit == '9')
            count[6]++;
        else
            count[digit - '0']++;
    }

    for(int i = 0; i < 9; i++) {
        if(i == 6)
            max_set = max(max_set, count[6] / 2 + count[6] % 2);
        else
            max_set = max(max_set, count[i]);
    }
    cout << max_set << endl;
    return 0;
}