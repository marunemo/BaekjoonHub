#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

queue<pair<int, bool>> magic;
queue<pair<int, bool>> result;
unordered_map<int, bool[2]> checked;

int main() {
    int a, b;
    int magic_count = 0;
    pair<int, bool> top;

    cin >> a >> b;

    magic.push({a, true});
    while(!magic.empty()) {
        top = magic.front();
        magic.pop();

        if(top.first == b)
            break;

        if(!checked[top.first][top.second]) {
            checked[top.first][top.second] = true;

            if(top.first + 1 <= b)
                result.push({top.first + 1, top.second});
            if(top.first * 2 <= b)
                result.push({top.first * 2, top.second});
            if(top.second && top.first * 10 <= b)
                result.push({top.first * 10, !top.second});
        }

        if(magic.empty()) {
            magic = result;
            result = queue<pair<int, bool>>();
            magic_count++;
        }
    }

    cout << magic_count << endl;
    return 0;
}