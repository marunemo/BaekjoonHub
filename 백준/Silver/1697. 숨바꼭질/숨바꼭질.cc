#include <iostream>
#include <queue>

using namespace std;

bool visit[200000];

int main() {
    int subin, brother;
    queue<int> q;
    int date, size;
    bool not_found = true;

    cin >> subin >> brother;
    
    q.push(subin);
    visit[subin] = true;

    for(date = 0; !q.empty() && not_found; date += not_found) {
        size = q.size();
        
        while(size--) {
            subin = q.front();
            q.pop();

            if(subin == brother)
                not_found = false;
            if(subin > 0 && !visit[subin - 1]) {
                visit[subin - 1] = true;
                q.push(subin - 1);
            }
            if(subin < brother && !visit[subin + 1]) {
                visit[subin + 1] = true;
                q.push(subin + 1);
            }
            if(subin < brother && !visit[subin * 2]) {
                visit[subin * 2] = true;
                q.push(subin * 2);
            }
        }
    }
    cout << date << endl;
    return 0;
}