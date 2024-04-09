#include <iostream>
#define MOD 10007

using namespace std;

// 조합 메모
int Combination[53][53];

int main() {
    int card_count;
    int result = 0;

    // nCn과 nC0은 1가지 경우만 나옴
    for(int i = 0; i <= 52; i++) {
        Combination[i][i] = 1;
        Combination[i][0] = 1;
    }
    // 1부터 52까지의 모든 조합 메모
    // nCr = (n-1)C(r-1) + (n-1)C(r), 즉 n개 중 r개를 뽑는 방법은 원소 하나를 반드시 포함하는 경우와 포함하지 않는 경우의 합
    for(int i = 1; i <= 52; i++) {
        for(int j = 1; j < i; j++)
            Combination[i][j] = (Combination[i - 1][j] + Combination[i - 1][j - 1]) % MOD;
    }

    // 카드 개수 입력
    cin >> card_count;
    
    /**
     * 수리통계학-포함과 배제의 원리: 홀수번째는 더하고 짝수번째는 뺌
     * 각 시행에서의 경우의 수는 포카드의 카드 세트를 가정하고,
     * 해당 포카드 세트의 조합과 포카드 조합을 제외한 전체 카드 중 추가로 뽑을 카드의 개수만큼의 조합을 곱한다
     * 추가로 뽑은 카드 중 포카드 세트가 나올 수 있으므로, 이를 포함과 배제의 원리에 따라 빼주거나 더해주는 것이다
     */
    for(int four_set = 1; four_set <= 13 && four_set * 4 <= card_count; four_set++) {
        if(four_set % 2)
            result += Combination[13][four_set] * Combination[52 - 4 * four_set][card_count - 4 * four_set];
        else
            result -= Combination[13][four_set] * Combination[52 - 4 * four_set][card_count - 4 * four_set];
        result %= MOD;
    }

    cout << (result + MOD) % MOD << endl;
    return 0;
}