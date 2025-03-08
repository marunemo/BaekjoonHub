#include <iostream>

using namespace std;

int marble_count, group_count;
int marble[300];

bool MakingChoice(int limit) {
    int marble_sum = 0;
    int total_group = 1;

    for(int i = 0; i < marble_count; i++) {
        if(marble[i] > limit) {
            return false;
        }

        if(marble_sum + marble[i] > limit) {
            total_group++;
            marble_sum = 0;
        }

        marble_sum += marble[i];
    }

    // total_group이 group_count보다 작을 경우, 전체 최댓값은 동일하고 total_group == group_count인 set을 만들 수 있음이 보장됨
    return total_group <= group_count;
}

void ConstructSolution(int limit, int member_count[300], int &members_index) {
    int marble_sum = 0;
    int total_member = 0;

    for(int i = 0; i < marble_count; i++) {
        if(marble_sum + marble[i] > limit) {
            member_count[members_index++] = total_member;
            
            marble_sum = 0;
            total_member = 0;
        }
        
        if(marble_count - i == group_count - members_index) {
            for(int j = 0; j < marble_count - i; j++) {
                member_count[members_index++] = ++total_member;
                total_member = 0;
            }
            break;
        }
        
        marble_sum += marble[i];
        total_member++;
    }


    // member_sum[members_index] = marble_sum;
    // member_count[members_index] = total_member;
    // members_index++;
}

// https://leetcode.com/problems/split-array-largest-sum/
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int max_marble = 0, sum_marble = 0;
    int left, right, mid;
    int min_max_sum;
    int member_count[300];
    int members_index = 0;

    cin >> marble_count >> group_count;
    for(int i = 0; i < marble_count; i++) {
        cin >> marble[i];

        max_marble = max(marble[i], max_marble);
        sum_marble += marble[i];
    }

    left = max_marble;
    right = sum_marble;
    while(left <= right) {
        mid = (left + right) / 2;
        
        if(MakingChoice(mid)) {
            min_max_sum = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    ConstructSolution(min_max_sum, member_count, members_index);
    
    cout << min_max_sum << '\n';
    for(int i = 0; i < members_index; i++) {
        cout << member_count[i] << ' ';
    }

    cout << endl;
    return 0;
}