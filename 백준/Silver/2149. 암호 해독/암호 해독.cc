#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string key;
    string encrypt;
    int len_key, len_encrypt;
    int size;
    vector<vector<char>> col_vec;
    vector<bool> checked;
    string sorted_key;
    vector<vector<char>> decrypt;

    cin >> key >> encrypt;

    len_key = key.length();
    len_encrypt = encrypt.length();
    size = len_encrypt / len_key;

    col_vec.resize(len_key);
    for(int i = 0; i < len_key; i++) {
        for(int j = 0; j < size; j++)
            col_vec[i].push_back(encrypt[i * size + j]);
    }

    sorted_key = key;
    sort(sorted_key.begin(), sorted_key.end());

    checked.resize(len_key, false);
    for(int i = 0; i < len_key; i++) {
        for(int j = 0; j < len_key; j++) {
            if(!checked[j] && key[i] == sorted_key[j]) {
                checked[j] = true;
                decrypt.push_back(col_vec[j]);
                break;
            }
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < len_key; j++)
            cout << decrypt[j][i];
    }
    cout << endl;
    return 0;
}