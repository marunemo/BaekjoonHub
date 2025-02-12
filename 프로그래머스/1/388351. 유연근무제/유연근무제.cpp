#include <string>
#include <vector>

using namespace std;

int next10(int time) {
    int hh = time / 100;
    int mm = time % 100;
    
    mm += 10;
    if(mm >= 60) {
        hh++;
        mm -= 60;
    }
    
    return hh * 100 + mm;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int idx = 0; idx < schedules.size(); idx++) {
        bool flag = true;
        for(int i = 0; i < 7 && flag; i++) {
            if((startday + i) % 7 == 0 || (startday + i) % 7 == 6)
                continue;
            
            flag = flag & timelogs[idx][i] <= next10(schedules[idx]);
        }
        answer += flag;
    }
    
    return answer;
}