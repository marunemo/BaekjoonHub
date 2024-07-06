#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string line;
    stringstream ss;
    vector<int> list;
    int num, size;
    vector<int> scale;

    while(getline(cin, line)) {
        ss.clear();
        ss.str(line);

        list.clear();
        while(ss >> num)
            list.push_back(num);
        
        size = list.size();
        scale.resize(size);
        for(int i = 0; i < size; i++) {
            scale[i] = list[i];
            if(i > 0)
                scale[i] *= list[i - 1];
            if(i < size - 1)
                scale[i] *= list[i + 1];
        }

        for(int num: scale)
            cout << num << ' ';
        cout << '\n';
    }
    return 0;
}