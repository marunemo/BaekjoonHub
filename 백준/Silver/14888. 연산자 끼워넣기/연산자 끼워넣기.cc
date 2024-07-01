#include <iostream>
#define INF 10000000000

using namespace std;
using ll = long long;

ll num_count;
ll num[100];
ll oper[4];

ll FindMax(int index, ll result) {
    if(index == num_count)
        return result;
    
    ll max_result = -INF;

    if(oper[0]) {
        oper[0]--;
        max_result = max(max_result, FindMax(index + 1, result + num[index]));
        oper[0]++;
    }
    
    if(oper[1]) {
        oper[1]--;
        max_result = max(max_result, FindMax(index + 1, result - num[index]));
        oper[1]++;
    }
    
    if(oper[2]) {
        oper[2]--;
        max_result = max(max_result, FindMax(index + 1, result * num[index]));
        oper[2]++;
    }
    
    if(oper[3]) {
        oper[3]--;
        max_result = max(max_result, FindMax(index + 1, result / num[index]));
        oper[3]++;
    }
    
    return max_result;
}

ll FindMin(int index, ll result) {
    if(index == num_count)
        return result;
    
    ll min_result = INF;

    if(oper[0]) {
        oper[0]--;
        min_result = min(min_result, FindMin(index + 1, result + num[index]));
        oper[0]++;
    }
    
    if(oper[1]) {
        oper[1]--;
        min_result = min(min_result, FindMin(index + 1, result - num[index]));
        oper[1]++;
    }
    
    if(oper[2]) {
        oper[2]--;
        min_result = min(min_result, FindMin(index + 1, result * num[index]));
        oper[2]++;
    }
    
    if(oper[3]) {
        oper[3]--;
        min_result = min(min_result, FindMin(index + 1, result / num[index]));
        oper[3]++;
    }
    
    return min_result;
}

int main() {
    cin >> num_count;
    for(int i = 0; i < num_count; i++)
        cin >> num[i];
    for(int i = 0; i < 4; i++)
        cin >> oper[i];

    cout << FindMax(1, num[0]) << '\n';
    cout << FindMin(1, num[0]) << '\n';
    return 0;
}