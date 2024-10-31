#include <iostream>
#define MAX_LEVEL 200

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int warrior_count, tower_height, date;
    int warrior_level, mob_level;
    int level_count[MAX_LEVEL] = {0};
    int max_lvl[201] = {0};
    int hunt_spot[201] = {0};
    pll move_reduced[MAX_LEVEL];
    pll prefix_sum[MAX_LEVEL];
    ll total_move, total_reduce;
    ll min_total_move, result_reduced;
    int min_x = 0, min_y = 0;

    cin >> warrior_count >> tower_height >> date;
    for(int i = 0; i < warrior_count; i++)  {
        cin >> warrior_level;
        level_count[warrior_level]++;
    }
    for(int i = 0; i < tower_height; i++) {
        cin >> mob_level;
        for(int lvl = mob_level; lvl < MAX_LEVEL && max_lvl[lvl] < mob_level; lvl++) {
            max_lvl[lvl] = mob_level;
            hunt_spot[lvl] = i + 1;
        }
    }

    min_total_move = (ll)warrior_count * tower_height * date;
    for(int x = 1; x <= tower_height; x++) {
        for(int y = x + 1; y <= tower_height; y++) {
            prefix_sum[0] = {0, 0};
            for(int lvl = 1; lvl < MAX_LEVEL; lvl++) {
                // 마법석 이용 안할시 vs 이용할 시
                if(hunt_spot[lvl] <= x + abs(y - hunt_spot[lvl]))
                    move_reduced[lvl] = {hunt_spot[lvl] - 1, 0};
                else
                    move_reduced[lvl] = {x + abs(y - hunt_spot[lvl]) - 1, hunt_spot[lvl] - (x + abs(y - hunt_spot[lvl]))};
                prefix_sum[lvl].first = move_reduced[lvl].first + prefix_sum[lvl - 1].first;
                prefix_sum[lvl].second = move_reduced[lvl].second + prefix_sum[lvl - 1].second;
            }

            total_move = total_reduce = 0;
            for(int lvl = 1; lvl < MAX_LEVEL; lvl++) {
                total_move += (prefix_sum[min(lvl + date, MAX_LEVEL) - 1].first - prefix_sum[lvl - 1].first) * level_count[lvl];
                total_reduce += (prefix_sum[min(lvl + date, MAX_LEVEL) - 1].second - prefix_sum[lvl - 1].second) * level_count[lvl];
            }

            if(total_move < min_total_move) {
                min_total_move = total_move;
                min_x = x;
                min_y = y;
                result_reduced = total_reduce;
            }
        }
    }

    cout << min_x << ' ' << min_y << '\n' << result_reduced << endl;
    return 0;
}