#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define MOD 10007

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int student_count, block_count, height;
    vector<vector<int>> count;
    string line;
    stringstream sstream;
    int block;
    int curr;

    cin >> student_count >> block_count >> height;
    count.resize(2, vector<int>(height + 1, 0));

    getline(cin, line); // remove the rest line
    for(curr = 1; student_count--; curr = !curr) {
        getline(cin, line);

        sstream.clear();
        sstream.str(line);

        for(int h = 1; h <= height; h++)
            count[curr][h] = count[!curr][h];

        while(sstream >> block) {
            for(int h = 1; h <= height; h++) {
                if(h == block)
                    count[curr][h]++;
                else if(h > block && count[!curr][h - block])
                    count[curr][h] += count[!curr][h - block];
                count[curr][h] %= MOD;
            }
        }
    }

    cout << count[!curr][height] << endl;
    return 0;
}