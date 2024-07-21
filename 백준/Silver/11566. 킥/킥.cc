#include <iostream>

using namespace std;

bool InDream(int start, int len, int interval, int real[1000], int dream[1000]) {
    for(int i = 0; i < len; i++) {
        if(dream[start + interval * i] != real[i])
            return false;
    }
    return true;
}

int main() {
    int real_count;
    int real[1000];
    int dream_count;
    int dream[1000];
    int min_depth = 2000;
    int max_depth = -1;

    cin >> real_count;
    for(int i = 0; i < real_count; i++)
        cin >> real[i];
    cin >> dream_count;
    for(int i = 0; i < dream_count; i++)
        cin >> dream[i];

    for(int depth = 0; real_count + depth * (real_count - 1) <= dream_count; depth++) {
        for(int i = 0; i + real_count + depth * (real_count - 1) <= dream_count; i++) {
            if(InDream(i, real_count, depth + 1, real, dream)) {
                min_depth = min(depth, min_depth);
                max_depth = max(depth, max_depth);
            }
        }
    }

    if(max_depth == -1)
        cout << -1 << endl;
    else
        cout << min_depth << ' ' << max_depth << endl;
    return 0;
}