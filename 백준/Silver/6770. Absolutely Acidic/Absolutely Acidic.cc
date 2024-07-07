#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int count, value;
    vector<int> reading;
    unordered_map<int, int> frequency;
    vector<int> candidate;
    int max_freq, diff;
    int largest;

    cin >> count;
    for(int i = 0; i < count; i++) {
        cin >> value;

        if(!frequency[value])
            reading.push_back(value);
        frequency[value]++;
    }
    sort(reading.begin(), reading.end());

    max_freq = 0;
    for(int value: reading) {
        if(frequency[value] == max_freq)
            candidate.push_back(value);
        else if(frequency[value] > max_freq) {
            max_freq = frequency[value];
            candidate = vector<int>({value});
        }
    }

    if(candidate.size() > 1) {
        diff = candidate.back() - candidate.front();
        cout << diff << endl;
        return 0;
    }

    max_freq = 0;
    largest = candidate[0];
    for(int value: reading) {
        if(value == largest)
            continue;
            
        if(frequency[value] == max_freq)
            candidate.push_back(value);
        else if(frequency[value] > max_freq) {
            max_freq = frequency[value];
            candidate = vector<int>({value});
        }
    }

    for(int value: candidate)
        diff = max(diff, abs(largest - value));
    cout << diff << endl;
    return 0;
}