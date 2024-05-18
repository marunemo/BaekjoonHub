#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> desc_num;

void DescFinder(ll num) {
    desc_num.push_back(num);
    for(int i = num % 10 - 1; i >= 0; i--)
        DescFinder(num * 10 + i);
}

int main() {
    for(int i = 0; i < 10; i++)
        DescFinder(i);
    sort(desc_num.begin(), desc_num.end());

    int order;
    cin >> order;

    if(order > desc_num.size())
        cout << -1 << endl;
    else
        cout << desc_num[order - 1] << endl;
    return 0;
}