#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int main() {
    int count, value;
    vector<pii> reading;
    unordered_map<int, int> frequency;
    int index;

    // input
    cin >> count;
    for(int i = 0; i < count; i++) {
        cin >> value;

        if(!frequency[value])
            reading.push_back({value, 0});
        frequency[value]++;

    }

    // 각각의 frequency를 reading에 매핑
    for(int i = 0; i < frequency.size(); i++)
        reading[i].second = frequency[reading[i].first];

    // frequency에 대해 내림차순, 같은 경우 값에 대해 오름차순 정렬
    sort(reading.begin(), reading.end(), [](pii a, pii b) {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    // 최빈값이 하나가 아닌 경우
    if(reading[0].second == reading[1].second) {
        for(index = 1; index < reading.size() && reading[index].second == reading[0].second; index++);
        cout << reading[index - 1].first - reading[0].first << endl;
    }
    // 최빈값이 하나인 경우
    else {
        for(index = 2; index < reading.size() && reading[index].second == reading[1].second; index++);
        cout << max(abs(reading[index - 1].first - reading[0].first), abs(reading[1].first - reading[0].first)) << endl;
    }
    return 0;
}