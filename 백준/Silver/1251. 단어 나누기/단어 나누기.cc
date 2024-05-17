#include <iostream>
#include <string>

using namespace std;

string ReverseString(string str, int start, int end) {
    string substring = "";
    for(int i = start; i < end; i++)
        substring = str[i] + substring;
    return substring;
}

int main() {
    string word;
    int len;
    string result = "";

    cin >> word;
    len = word.length();
    for(int i = 0; i < len; i++)
        result += 'z';

    for(int sec1 = 1; sec1 < len - 1; sec1++) {
        for(int sec2 = sec1 + 1; sec2 < len; sec2++)
            result = min(result, ReverseString(word, 0, sec1) + ReverseString(word, sec1, sec2) + ReverseString(word, sec2, len));
    }
    cout << result << endl;
    return 0;
}