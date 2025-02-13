#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int window[24] = {0};
    int server = 0;
    
    for(int i = 0; i < k && i < players.size(); i++) {
        if(players[i] / m > server) {
            window[i] = players[i] / m - server;
            answer += players[i] / m - server;
            server = players[i] / m;
        }
    }
    
    for(int i = k; i < players.size(); i++) {
        server -= window[i - k];
        
        if(players[i] / m > server) {
            window[i] = players[i] / m - server;
            answer += players[i] / m - server;
            server = players[i] / m;
        }
    }
    
    return answer;
}