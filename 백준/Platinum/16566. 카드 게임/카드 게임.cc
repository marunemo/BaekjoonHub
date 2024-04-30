#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> deck;
vector<int> draw_card;

int UnionFind(int card) {
    if(draw_card[card] == card)
        return card;
    return draw_card[card] = UnionFind(draw_card[card]);
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    int opponent;
    int left, right, mid;

    cin >> n >> m >> k;

    deck = vector<int>(m);
    for(int i = 0; i < m; i++)
        cin >> deck[i];
    sort(deck.begin(), deck.end());

    draw_card = vector<int>(m);
    for(int i = 0; i < m; i++)
        draw_card[i] = i;
    
    while(k--) {
        cin >> opponent;

        // upper bound
        left = 0;
        right = m - 1;
        while(left < right) {
            mid = (left + right) / 2;
            if(deck[mid] <= opponent)
                left = mid + 1;
            else
                right = mid;
        }

        // union find
        cout << deck[draw_card[UnionFind(right)]] << '\n';
        draw_card[draw_card[right]]++;
    }
    return 0;
}