#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int count, days;
    
    for(int i = 0; i < progresses.size(); ) {
        count = 0;
        days = (100 - progresses[i]) / speeds[i] + ((100 - progresses[i]) % speeds[i] != 0);
        
        for(int j = i; j < progresses.size(); j++)
            progresses[j] += speeds[j] * days;
        
        for(; i < progresses.size() && progresses[i] >= 100; i++)
            count++;
        answer.push_back(count);
    }
    
    return answer;
}