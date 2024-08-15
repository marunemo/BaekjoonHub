#include <iostream>

using namespace std;

struct pa {
    int perimeter;
    int area;

    pa& operator+(pa const &x) {
        perimeter += x.perimeter;
        area += x.area;
        return *this;
    }

    bool operator<(pa const &x) const {
        if(area == x.area)
            return perimeter > x.perimeter;
        return area < x.area;
    }
};

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int n;
bool map[1000][1000];
bool visit[1000][1000];

bool InRange(int row, int col) {
    if(row < 0)
        return false;
    if(row >= n)
        return false;
    if(col < 0)
        return false;
    if(col >= n)
        return false;
    return true;
}

pa DFS(int row, int col) {
    int new_r, new_c;
    pa result;
    result.perimeter = 0;
    result.area = 1;

    visit[row][col] = true;
    for(int i = 0; i < 4; i++) {
        new_r = row + dy[i];
        new_c = col + dx[i];

        if(!InRange(new_r, new_c))
            result.perimeter++;
        else if(!map[new_r][new_c])
            result.perimeter++;
        else if(!visit[new_r][new_c])
            result = result + DFS(new_r, new_c);
    }
    
    return result;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    char blob;
    pa result;
    result.perimeter = 0;
    result.area = 0;

    cin >> n;
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            cin >> blob;
            map[row][col] = blob == '#';
        }
    }

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            if(!visit[row][col] && map[row][col])
                result = max(result, DFS(row, col));
        }
    }

    cout << result.area << ' ' << result.perimeter << endl;
    return 0;
}