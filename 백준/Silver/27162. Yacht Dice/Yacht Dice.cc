#include <iostream>

using namespace std;

int Check(bool rule[12], int count[7]) {
    int max_score = 0;
    int two_index = 0;
    int three_index = 0;
    int four_index = 0;
    int five_index = 0;
    bool little = true;
    bool large = true;
    int sum = 0;
    
    for(int dice = 1; dice <= 6; dice++) {
        max_score = max(max_score, rule[dice - 1] * dice * count[dice]);
        
        if(count[dice] == 2)
            two_index = dice;
        else if(count[dice] == 3)
            three_index = dice;
        else if(count[dice] == 4)
            four_index = dice;
        else if(count[dice] == 5)
            five_index = dice;
        sum += dice * count[dice];
    }
    
    if(rule[6] && four_index)
        max_score = max(max_score, four_index * 4);
    
    if(rule[7] && two_index && three_index)
        max_score = max(max_score, two_index * 2 + three_index * 3);

    for(int dice = 1; dice <= 5 && little; dice++)
        little = count[dice];
    if(rule[8] && little)
        max_score = max(max_score, 30);

    for(int dice = 2; dice <= 6 && large; dice++)
        large = count[dice];
    if(rule[9] && large)
        max_score = max(max_score, 30);
    
    if(rule[10] && five_index)
        max_score = max(max_score, 50);

    if(rule[11])
        max_score = max(max_score, sum);

    return max_score;
}

int main() {
    char able;
    bool rule[12];
    int dice;
    int count[7] = {0};
    int max_score = 0;

    for(int i = 0; i < 12; i++) {
        cin >> able;
        rule[i] = able == 'Y';
    }

    for(int i = 0; i < 3; i++) {
        cin >> dice;
        count[dice]++;
    }

    for(int first = 1; first <= 6; first++) {
        count[first]++;
        for(int second = 1; second <= 6; second++) {
            count[second]++;
            max_score = max(max_score, Check(rule, count));
            count[second]--;
        }
        count[first]--;
    }

    cout << max_score << endl;
    return 0;
}