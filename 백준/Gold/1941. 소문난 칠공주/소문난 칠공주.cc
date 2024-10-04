#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const int dir[4] = {-5, -1, 5, 1};

string map = "";
unordered_map<string, bool> check;

bool IsValid(string &status, int i) {
    for(int d = 0; d < 4; d++) {
        if(i % 5 == 0 && dir[d] == -1)
            continue;
        if(i % 5 == 4 && dir[d] == 1)
            continue;
        if(i + dir[d] < 0 || i + dir[d] >= 25)
            continue;
        
        if(status[i + dir[d]] == '1')
            return true;
    }
    return false;
}

int DFS(string &status, int s, int y) {
    if(y == 4)
        return 0;
    if(s + y == 7)
        return 1;

    int count = 0;
    for(int i = 0; i < 25; i++) {
        if(status[i] == '0') {
            if(!IsValid(status, i))
                continue;
            
            status[i] = '1';
            if(!check[status]) {
                check[status] = true;
                count += DFS(status, s + (map[i] == 'S'), y + (map[i] == 'Y'));
            }
            status[i] = '0';
        }
    }
    return count;
}

int main() {
    string status = "0000000000000000000000000";
    string row;
    int count = 0;

    for(int i = 0; i < 5; i++) {
        cin >> row;
        map += row;
    }

    for(int i = 0; i < 25; i++) {
        status[i] = '1';
        check[status] = true;
        count += DFS(status, (map[i] == 'S'), (map[i] == 'Y'));;
        status[i] = '0';
    }
    cout << count << endl;
    return 0;
}