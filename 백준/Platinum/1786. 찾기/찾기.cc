#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string text;
    string pattern;
    vector<int> prefix;
    int len, i, j;
    vector<int> index;

    getline(cin, text);
    getline(cin, pattern);

    pattern = " " + pattern;

    len = pattern.length();
    prefix.resize(len);

    i = 2;
    j = 0;
    prefix[0] = 0;
    prefix[1] = 0;
    for(; i < len; i++) {
        while(j > 0 && pattern[i] != pattern[j + 1])
            j = prefix[j];
        
        if(pattern[i] == pattern[j + 1])
            prefix[i] = ++j;
        else
            prefix[i] = 0;
    }

    j = 0;
    for(i = 0; i < text.length(); i++) {
        while(j > 0 && text[i] != pattern[j + 1])
            j = prefix[j];
        
        if(text[i] == pattern[j + 1])
            j++;

        if(j == len - 1)
            index.push_back(i - (j - 1) + 1);
    }

    cout << index.size() << '\n';
    for(int start: index)
        cout << start << '\n';
    return 0;
}