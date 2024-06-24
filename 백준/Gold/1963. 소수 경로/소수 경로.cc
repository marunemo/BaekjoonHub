#include <iostream>
#include <queue>

using namespace std;

bool prime[10000] = {false};
queue<int> prime_q;
queue<int> next_q;
vector<bool> visit;

bool IsPrime(int num) {
    for(int div = 2; div * div <= num; div++) {
        if(num % div == 0)
            return false;
    }
    return true;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int count;
    int src, dest;
    int tmp;
    bool flag;

    for(int i = 1000; i < 10000; i++)
        prime[i] = IsPrime(i);
    
    cin >> tc;
    while(tc--) {
        cin >> src >> dest;

        count = 0;
        prime_q = queue<int>({src});
        next_q = queue<int>();
        visit = vector<bool>(10000, false);
        visit[src] = true;
        flag = false;

        while(!prime_q.empty() && !flag) {
            src = prime_q.front();
            prime_q.pop();

            if(src == dest) {
                flag = true;
                break;
            }

            for(int i = 1; i <= 9; i++) {
                tmp = src % 1000 + i * 1000;
                if(prime[tmp] && !visit[tmp]) {
                    visit[tmp] = true;
                    next_q.push(tmp);
                }
            }

            for(int i = 0; i <= 9; i++) {
                tmp = (src / 1000 * 1000) + src % 100 + i * 100;
                if(prime[tmp] && !visit[tmp]) {
                    visit[tmp] = true;
                    next_q.push(tmp);
                }
            }

            for(int i = 0; i <= 9; i++) {
                tmp = (src / 100 * 100) + src % 10 + i * 10;
                if(prime[tmp] && !visit[tmp]) {
                    visit[tmp] = true;
                    next_q.push(tmp);
                }
            }

            for(int i = 0; i <= 9; i++) {
                tmp = (src / 10 * 10) + i;
                if(prime[tmp] && !visit[tmp]) {
                    visit[tmp] = true;
                    next_q.push(tmp);
                }
            }

            if(prime_q.empty()) {
                prime_q = next_q;
                next_q = queue<int>();
                count++;
            }
        }

        if(flag)
            cout << count << '\n';
        else
            cout << "Impossible\n";
    }

    return 0;
}