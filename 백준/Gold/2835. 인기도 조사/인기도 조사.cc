#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#define MAX_TIME 86400 // 24h * 60m * 60s

using namespace std;

vector<long long> sum_tree;
vector<long long> lazy;

int time_to_second(int hh, int mm, int ss) {
    return hh * 3600 + mm * 60 + ss;
}

void propagate(int node, int start, int end) {
    if(lazy[node]) {
        sum_tree[node] += lazy[node] * (end - start + 1);
        if(start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right) {
    propagate(node, start, end);
    if(end < left || right < start)
        return;
    if(left <= start && end <= right) {
        sum_tree[node] += 1 * (end - start + 1);
        if(start != end) {
            lazy[node * 2]++;
            lazy[node * 2 + 1]++;
        }
    }
    else {
        update(node * 2, start, (start + end) / 2, left, right);
        update(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
        sum_tree[node] = sum_tree[node * 2] + sum_tree[node * 2 + 1];
    }
}

long long query(int node, int start, int end, int left, int right) {
    propagate(node, start, end);
    if(end < left || right < start)
        return 0;
    if(left <= start && end <= right)
        return sum_tree[node];
    return query(node * 2, start, (start + end) / 2, left, right) + query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
    // Fast IO
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    // floating point
    cout.precision(10);
    cout << fixed;

    // 24:00:00 to second
    int height = ceil(log2(MAX_TIME));
    sum_tree.resize(1 << (height + 1), 0);
    lazy.resize(1 << (height + 1), 0);

    int n;
    cin >> n;

    string time;
    long long total_popular = 0;

    int hh, mm, ss;
    int start, end;
    for(int i = 0; i < n; i++) {
        cin >> time;
        hh = (time[0] - '0') * 10 + (time[1] - '0');
        mm = (time[3] - '0') * 10 + (time[4] - '0');
        ss = (time[6] - '0') * 10 + (time[7] - '0');
        start = time_to_second(hh, mm, ss);

        cin >> time; // flush '-'

        cin >> time;
        hh = (time[0] - '0') * 10 + (time[1] - '0');
        mm = (time[3] - '0') * 10 + (time[4] - '0');
        ss = (time[6] - '0') * 10 + (time[7] - '0');
        end = time_to_second(hh, mm, ss);

        if(start > end) {
            update(1, 0, MAX_TIME - 1, start, MAX_TIME - 1);
            update(1, 0, MAX_TIME - 1, 0, end);
            total_popular += (MAX_TIME - start) + (end + 1);
        }
        else {
            update(1, 0, MAX_TIME - 1, start, end);
            total_popular += end - start + 1;
        }

    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> time;
        hh = (time[0] - '0') * 10 + (time[1] - '0');
        mm = (time[3] - '0') * 10 + (time[4] - '0');
        ss = (time[6] - '0') * 10 + (time[7] - '0');
        start = time_to_second(hh, mm, ss);

        cin >> time; // flush '-'

        cin >> time;
        hh = (time[0] - '0') * 10 + (time[1] - '0');
        mm = (time[3] - '0') * 10 + (time[4] - '0');
        ss = (time[6] - '0') * 10 + (time[7] - '0');
        end = time_to_second(hh, mm, ss);

        double result = 0;
        double range = 0; // end - start + 1(시작과 끝의 초를 모두 포함)
        if(start > end) {
            result = total_popular - query(1, 0, MAX_TIME - 1, end + 1, start - 1);
            range = (MAX_TIME - start) + (end + 1);
        }
        else {
            result = query(1, 0, MAX_TIME - 1, start, end);
            range = end - start + 1;
        }
        cout << (result / range) << '\n';
    }
    return 0;
}