#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int a_count = 0;
    int b_count, min_b_count;
    int len;

    cin >> str;
    for(char c: str) {
        a_count += c == 'a';
    }

    len = str.length();
    min_b_count = a_count;
    for(int i = 0; i < len; i++) {
        b_count = 0;
        for(int j = 0; j < a_count; j++) {
            b_count += str[(i + j) % len] == 'b';
        }

        min_b_count = min(b_count, min_b_count);
    }
    cout << min_b_count << endl;
    return 0;
}