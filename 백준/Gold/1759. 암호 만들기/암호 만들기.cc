#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int password_length, alpha_count;
char alpha[15];
vector<string> result;

bool IsVowel(char letter) {
    if(letter == 'a')
        return true;
    if(letter == 'e')
        return true;
    if(letter == 'i')
        return true;
    if(letter == 'o')
        return true;
    if(letter == 'u')
        return true;
    return false;
}

void FindProbablity(string password, int index, int vowel, int consonant) {
    if(password.length() == password_length) {
        if(vowel < 1 || consonant < 2)
            return;
        
        result.push_back(password);
    }

    if(index == alpha_count)
        return;
    
    for(int i = index; i < alpha_count; i++)
        FindProbablity(password + alpha[i], i + 1, vowel + IsVowel(alpha[i]), consonant + !IsVowel(alpha[i]));
}

int main() {
    cin >> password_length >> alpha_count;
    for(int i = 0; i < alpha_count; i++)
        cin >> alpha[i];
    sort(alpha, alpha + alpha_count);

    FindProbablity("", 0, 0, 0);

    for(auto password: result)
        cout << password << '\n';
    return 0;
}