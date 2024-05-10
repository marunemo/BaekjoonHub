#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

pair<string, string> Split(string text) {
    pair<string, string> friends = {"", ""};
    bool first = true;
    for(auto t: text) {
        if(t == ' ')
            first = false;
        else if(first)
            friends.first += t;
        else
            friends.second += t;
    }
    return friends;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, unordered_map<string, int>> gift_count;
    unordered_map<string, int> gift_point;
    int gift;
    
    for(auto gift: gifts) {
        auto [give, take] = Split(gift);
        gift_count[give][take]++;
        gift_point[give]--;
        gift_point[take]++;
    }
    
    for(auto give: friends) {
        gift = 0;
        for(auto take: friends) {
            if(gift_count[give][take] > gift_count[take][give])
                gift++;
            else if(gift_count[give][take] == gift_count[take][give]) {
                if(gift_point[give] < gift_point[take])
                    gift++;
            }
        }
        answer = max(answer, gift);
    }
    return answer;
}