#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void DFS(unordered_map<string, string> &map, unordered_map<string, bool> &visit, string person) {
    if(visit[person])
        return;
    
    visit[person] = true;
    DFS(map, visit, map[person]);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int people;
    unordered_map<string, string> map;
    vector<string> list;
    string person, manito;
    unordered_map<string, bool> visit;
    int cycle;
    int tc = 0;

    cin >> people;
    while(people) {
        map.clear();
        visit.clear();
        list = vector<string>();

        while(people--) {
            cin >> person >> manito;
            map[person] = manito;
            list.push_back(person);
        }

        cycle = 0;
        for(string person: list) {
            if(!visit[person]) {
                DFS(map, visit, person);
                cycle++;
            }
        }

        cout << (++tc) << ' ' << cycle << '\n';
        cin >> people;
    }
    return 0;
}