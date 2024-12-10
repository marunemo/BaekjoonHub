#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string word[100000];
unordered_map<string, int> frequency;

bool Compare(string a, string b) {
    if(frequency[a] != frequency[b])
        return frequency[a] > frequency[b];
    if(a.length() != b.length())
        return a.length() > b.length();
    return a < b;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int count, min_len;
    int word_count = 0;
    string eng;

    cin >> count >> min_len;
    while(count--) {
        cin >> eng;
        if(eng.length() >= min_len) {
            if(!frequency[eng])
                word[word_count++] = eng;
            frequency[eng]++;
        }
    }
    sort(word, word + word_count, Compare);

    for(int i = 0; i < word_count; i++)
        cout << word[i] << '\n';
    return 0;
}