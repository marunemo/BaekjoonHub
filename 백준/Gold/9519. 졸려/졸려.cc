#include <iostream>
#include <string>

using namespace std;

int main() {
    int blink;
    string anagram;
    int len;
    int left, right;
    int index[1000];
    int next[1000];
    char reorder[1001] = {0};

    cin >> blink >> anagram;
    
    len = anagram.length();
    left = 0;
    right = len - 1;
    for(int i = 0; i < len; i++) {
        if(i % 2 == 0)
            index[left++] = i;
        else
            index[right--] = i;
    }

    while(blink) {
        if(blink & 1) {
            for(int i = 0; i < len; i++)
                reorder[i] = anagram[index[i]];
            anagram = string(reorder);
        }

        for(int i = 0; i < len; i++)
            next[i] = index[index[i]];
        for(int i = 0; i < len; i++)
            index[i] = next[i];

        blink >>= 1;
    }
    
    cout << anagram << endl;
    return 0;
}