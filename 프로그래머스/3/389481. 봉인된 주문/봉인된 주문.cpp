#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void NextVector(vector<int> &vec) {
    bool carry = true;
    
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] + carry == 26) {
            vec[i] = (vec[i] + carry) % 26;
            carry = true;
        }
        else {
            vec[i] = (vec[i] + carry) % 26;
            carry = false;
        }
    }
    
    if(carry)
        vec.push_back(0);
}

vector<int> str2vec(string str) {
    vector<int> vec;
    for(int i = str.length() - 1; i >= 0; i--)
        vec.push_back(str[i] - 'a');
    return vec;
}

string vec2str(vector<int> vec) {
    string str = "";
    for(int i = 0; i < vec.size(); i++)
        str = (char)('a' + vec[i]) + str;
    return str;
}

bool Compare(vector<int> &a, vector<int> &b) {
    if(a.size() == b.size()) {
        for(int i = a.size() - 1; i >= 0; i--) {
            if(a[i] != b[i])
                return a[i] < b[i];
        }
        return true;
    }
    return a.size() < b.size();
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    vector<int> curr;
    vector<vector<int>> bans_vec;
    
    while(n) {
        n--;
        curr.push_back(n % 26);
        n /= 26;
    }
    
    for(string ban: bans)
        bans_vec.push_back(str2vec(ban));
    sort(bans_vec.begin(), bans_vec.end(), Compare);
    
    for(vector<int> ban: bans_vec) {
        if(!Compare(ban, curr))
            break;
        
        NextVector(curr);
    }
    
    answer = vec2str(curr);
    return answer;
}