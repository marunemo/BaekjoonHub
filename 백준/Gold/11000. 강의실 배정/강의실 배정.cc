#include <iostream>
#include <queue>

using namespace std;
using Lecture = pair<int, int>;

priority_queue<Lecture, vector<Lecture>, greater<Lecture>> lectures;
priority_queue<int, vector<int>, greater<int>> end_time;

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int lecture_count;
    Lecture top;
    int room, room_size;

    cin >> lecture_count;
    while(lecture_count--) {
        cin >> top.first >> top.second;
        lectures.push(top);
    }

    top = lectures.top();
    lectures.pop();
    end_time.push(top.second);

    while(!lectures.empty()) {
        top = lectures.top();
        lectures.pop();

        if(end_time.top() <= top.first)
            end_time.pop();
        end_time.push(top.second);
    }

    cout << end_time.size() << endl;
    return 0;
}