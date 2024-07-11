#include <iostream>
#define INF 1000000000

using namespace std;
using pii = pair<int, int>;

int Evaluate(int num[11], char oper[10], int n) {
    int eval_num[11];
    int eval_oper[10];
    int index = 0;
    int result = 0;

    eval_num[index] = num[index];
    for(int i = 0; i < n; i++) {
        if(oper[i] == '*')
            eval_num[index] *= num[i + 1];
        else if(oper[i] == '/')
            eval_num[index] /= num[i + 1];
        else {
            eval_oper[index++] = oper[i];
            eval_num[index] = num[i + 1];
        }
    }

    result = eval_num[0];
    for(int i = 0; i < index; i++) {
        if(eval_oper[i] == '+')
            result += eval_num[i + 1];
        else if(eval_oper[i] == '-')
            result -= eval_num[i + 1];
    }

    return result;
}

pii MaxMin(int num[11], char oper[10], int count[4], int n, int depth = 0) {
    pii result;
    pii mm = {-INF, INF};
    
    if(n == depth) {
        result.first = Evaluate(num, oper, n);
        return {result.first, result.first};
    }

    if(count[0]) {
        count[0]--;
        oper[depth] = '+';
        result = MaxMin(num, oper, count, n, depth + 1);
        count[0]++;

        mm.first = max(mm.first, result.first);
        mm.second = min(mm.second, result.second);
    }

    if(count[1]) {
        count[1]--;
        oper[depth] = '-';
        result = MaxMin(num, oper, count, n, depth + 1);
        count[1]++;

        mm.first = max(mm.first, result.first);
        mm.second = min(mm.second, result.second);
    }

    if(count[2]) {
        count[2]--;
        oper[depth] = '*';
        result = MaxMin(num, oper, count, n, depth + 1);
        count[2]++;

        mm.first = max(mm.first, result.first);
        mm.second = min(mm.second, result.second);
    }

    if(count[3]) {
        count[3]--;
        oper[depth] = '/';
        result = MaxMin(num, oper, count, n, depth + 1);
        count[3]++;

        mm.first = max(mm.first, result.first);
        mm.second = min(mm.second, result.second);
    }

    return mm;
}

int main() {
    int n;
    int num[11];
    char oper[10];
    int count[4];
    pii result;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    for(int i = 0; i < 4; i++)
        cin >> count[i];
    
    result = MaxMin(num, oper, count, n - 1);
    cout << result.first << '\n' << result.second << endl;
    return 0;
}