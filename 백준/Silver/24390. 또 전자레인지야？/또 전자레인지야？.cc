#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    char time[6];
    int minute = 0;
    int second = 0;
    queue<pair<int, bool>> curr;
    queue<pair<int, bool>> next;
    unordered_map<int, bool> check;
    int count;

    cin >> time;
    
    minute += (time[0] - '0') * 10 + (time[1] - '0');
    second += (time[3] - '0') * 10 + (time[4] - '0');

    second += minute * 60;

    curr.push({0, false});

    count = 0;
    while(!curr.empty()) {
        auto [sec, start] = curr.front();
        curr.pop();

        if(sec == second && start)
            break;
        
        if(sec + 10 <= second && !check[sec + 10]) {
            check[sec + 10] = true;
            next.push({sec + 10, start});
        }

        if(sec + 60 <= second && !check[sec + 60]) {
            check[sec + 60] = true;
            next.push({sec + 60, start});
        }

        if(sec + 600 <= second && !check[sec + 600]) {
            check[sec + 600] = true;
            next.push({sec + 600, start});
        }

        if(!start)
            next.push({sec + (sec == 0 ? 30 : 0), true});
        else if(sec + 30 <= second && !check[sec + 30]) {
            check[sec + 30] = true;
            next.push({sec + 30, start});
        }
        
        if(curr.empty()) {
            curr = next;
            next = queue<pair<int, bool>>();
            count++;
        }
    }

    cout << count << endl;
    return 0;
}