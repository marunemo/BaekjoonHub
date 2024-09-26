#include <iostream>
#include <string>
#include <queue>

using namespace std;

string key_log;
char result[1000001];
deque<char> left_text, right_text;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int idx;
    
    cin >> tc;
    while(tc--) {
        cin >> key_log;

        for(char t: key_log) {
            if(t == '<') {
                if(!left_text.empty()) {
                    right_text.push_front(left_text.back());
                    left_text.pop_back();
                }
            }
            else if(t == '>') {
                if(!right_text.empty()) {
                    left_text.push_back(right_text.front());
                    right_text.pop_front();
                }
            }
            else if(t == '-') {
                if(!left_text.empty())
                    left_text.pop_back();
            }
            else
                left_text.push_back(t);
        }

        idx = 0;
        while(!left_text.empty()) {
            result[idx++] = left_text.front();
            left_text.pop_front();
        }
        while(!right_text.empty()) {
            result[idx++] = right_text.front();
            right_text.pop_front();
        }
        result[idx] = 0;
        cout << result << '\n';
    }
    return 0;
}