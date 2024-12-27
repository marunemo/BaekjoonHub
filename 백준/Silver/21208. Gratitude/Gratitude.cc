#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, k;
string word;
vector<string> words;
unordered_map<string, int> frequency, idx;

bool Compare(string a, string b) {
    if(frequency[a] == frequency[b])
        return idx[a] > idx[b];
    return frequency[a] > frequency[b];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    cin.ignore();
    
    for(int i = 0; i < 3 * n; i++) {
        getline(cin, word);
        if(!frequency[word])
            words.push_back(word);
        frequency[word]++;
        idx[word] = i;
    }
    sort(words.begin(), words.end(), Compare);

    for(int i = 0; i < k && i < words.size(); i++)
        cout << words[i] << '\n';
    return 0;
}