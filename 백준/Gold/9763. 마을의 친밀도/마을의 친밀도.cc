#include <iostream>

using namespace std;

struct Pos {
    int x, y, z;

    int Distance(Pos const &country) const {
        return abs(x - country.x) + abs(y - country.y) + abs(z - country.z);
    }
};

int country_count;
Pos country[10000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int first_two_min[2];
    int dist, min_dist = 10000;

    cin >> country_count;
    for(int i = 0; i < country_count; i++)
        cin >> country[i].x >> country[i].y >> country[i].z;
    
    for(int intermediate = 0; intermediate < country_count; intermediate++) {
        first_two_min[0] = first_two_min[1] = -1;
        for(int i = 0; i < country_count; i++) {
            if(i == intermediate)
                continue;

            dist = country[intermediate].Distance(country[i]);
            if(first_two_min[0] == -1)
                first_two_min[0] = dist;
            else if(first_two_min[0] >= dist) {
                first_two_min[1] = first_two_min[0];
                first_two_min[0] = dist;
            }
            else if(first_two_min[1] == -1 || first_two_min[1] > dist)
                first_two_min[1] = dist;
        }

        min_dist = min(min_dist, first_two_min[0] + first_two_min[1]);
    }

    cout << min_dist << endl;
    return 0;
}