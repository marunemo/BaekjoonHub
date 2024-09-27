#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, bool> check;
    
    for(int num: nums) {
        if(!check[num]) {
            check[num] = true;
            answer++;
        }
        
        if(answer == nums.size() / 2)
            break;
    }
    
    return answer;
}