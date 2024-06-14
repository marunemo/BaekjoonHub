#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Split(string const &ip) {
    string group = "";
    vector<string> token;
    
    for(char digit: ip) {
        if(digit != ':')
            group += digit;
        else if(token.empty()) {
            token.push_back(group);
            group = "";
        }
        else if(token.back() != "" || group != "") {
            token.push_back(group);
            group = "";
        }
    }
    token.push_back(group);

    return token;
}

vector<string> Decode(vector<string> const &ipv6) {
    vector<string> decoded = ipv6;
    int size = ipv6.size();
    string group;
    
    for(int i = 0; i < size && decoded.size() < 8; i++) {
        if(decoded[i] != "")
            continue;

        while(decoded.size() < 8)
            decoded.insert(decoded.begin() + i, "0000");
    }

    for(int i = 0; i < 8; i++) {
        group = decoded[i];
        while(group.length() < 4)
            group = "0" + group;
        decoded[i] = group;
    }

    return decoded;
}

int main() {
    string ip;
    vector<string> ipv6;
    vector<string> decoded_ipv6;

    cin >> ip;
    ipv6 = Split(ip);
    decoded_ipv6 = Decode(ipv6);

    for(int i = 0; i < 7; i++)
        cout << decoded_ipv6[i] << ':';
    cout << decoded_ipv6[7] << endl;
    return 0;
}