#include <iostream>
#include <queue>

using namespace std;

queue<int> sushi_type;
int type_count[3001] = {0};
int rotate_dish[3000] = {0};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int dish, types, seq_dish, coupon;
    int sushi;
    int max_types = 0;
    int curr_types = 0;

    cin >> dish >> types >> seq_dish >> coupon;
    
    // 쿠폰
    type_count[coupon]++;
    curr_types++;

    // 처음으로 먹게되는 연속된 초밥
    for(int i = 0; i < seq_dish; i++) {
        cin >> sushi;
        rotate_dish[i] = sushi;

        if(!type_count[sushi])
            curr_types++;
        type_count[sushi]++;
        sushi_type.push(sushi);

        dish--;
    }
    max_types = curr_types;

    // 나머지 초밥에 대해 sliding window
    while(dish--) {
        cin >> sushi;

        type_count[sushi_type.front()]--;
        if(!type_count[sushi_type.front()])
            curr_types--;
        sushi_type.pop();

        if(!type_count[sushi])
            curr_types++;
        type_count[sushi]++;
        sushi_type.push(sushi);

        max_types = max(max_types, curr_types);
    }

    for(int i = 0; i < seq_dish; i++) {
        sushi = rotate_dish[i];

        type_count[sushi_type.front()]--;
        if(!type_count[sushi_type.front()])
            curr_types--;
        sushi_type.pop();

        if(!type_count[sushi])
            curr_types++;
        type_count[sushi]++;
        sushi_type.push(sushi);

        max_types = max(max_types, curr_types);
    }
    cout << max_types << endl;
    return 0;
}