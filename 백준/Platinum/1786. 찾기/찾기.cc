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

    len = pattern.length();
    prefix.resize(len);

    i = 1;
    j = 0;
    prefix[0] = 0;
    for(; i < len; i++) {
        while(j > 0 && pattern[i] != pattern[j])
            j = prefix[j - 1];
        
        if(pattern[i] == pattern[j])
            prefix[i] = ++j;
    }

    j = 0;
    for(i = 0; i < text.length(); i++) {
        while(j > 0 && text[i] != pattern[j])
            j = prefix[j - 1];
        
        if(text[i] == pattern[j])
            j++;

        if(j == len)
            index.push_back(i - (j - 1) + 1);
    }

    cout << index.size() << '\n';
    for(int start: index)
        cout << start << '\n';
    return 0;
}