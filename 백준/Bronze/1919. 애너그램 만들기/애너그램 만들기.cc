#include <iostream>

using namespace std;

int alpha_count[26];

int main() {
    char word1[1001] = {0};
    char word2[1001] = {0};
    int count = 0;

    cin >> word1 >> word2;
    for(int i = 0; word1[i]; i++)
        alpha_count[word1[i] - 'a']++;
    for(int i = 0; word2[i]; i++)
        alpha_count[word2[i] - 'a']--;
    
    for(int i = 0; i < 26; i++)
        count += abs(alpha_count[i]);
    cout << count << endl;
    return 0;
}