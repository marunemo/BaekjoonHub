#include <iostream>
#include <vector>

using namespace std;
using Cloud = vector<vector<bool>>;
using Bucket = vector<vector<int>>;

const int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool InRange(int row, int col, int n) {
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

Cloud MoveCloud(Cloud const& cloud, int dir) {
    int n = cloud.size();
    Cloud next = Cloud(n, vector<bool>(n, false));

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            if(cloud[row][col])
                next[(row + dy[dir] + n) % n][(col + dx[dir] + n) % n] = cloud[row][col];
        }
    }

    return next;
}


Bucket RainDance(Bucket const& bucket, Cloud const& cloud) {
    int n = bucket.size();
    Bucket next = bucket;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            if(!cloud[row][col])
                continue;

            // 구름에서 비가 내려 바구니에 물의 양 1 증가
            next[row][col]++;

            // 대각선 검사
            for(int i = 1; i < 8; i += 2) {
                if(!InRange(row + dy[i], col + dx[i], n))
                    continue;
                
                next[row][col] += (bucket[row + dy[i]][col + dx[i]] > 0) | cloud[row + dy[i]][col + dx[i]];
            }
        }
    }

    return next;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, query;
    Bucket bucket;
    Cloud cloud;
    int dir, dist;
    int water = 0;

    cin >> n >> query;
    bucket = Bucket(n, vector<int>(n));
    cloud = Cloud(n, vector<bool>(n, false));

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++)
            cin >> bucket[row][col];
    }

    cloud[n - 1][0] = cloud[n - 1][1] = cloud[n - 2][0] = cloud[n - 2][1] = true;
    while(query--) {
        cin >> dir >> dist;

        for(int i = 0; i < dist; i++)
            cloud = MoveCloud(cloud, dir - 1);
        bucket = RainDance(bucket, cloud);

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(cloud[row][col])
                    cloud[row][col] = false;
                else if(bucket[row][col] >= 2) {
                    bucket[row][col] -= 2;
                    cloud[row][col] = true;
                }
            }
        }
    }

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++)
            water += bucket[row][col];
    }

    cout << water << endl;
    return 0;
}