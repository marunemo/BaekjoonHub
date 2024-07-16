#include <iostream>

using namespace std;

/**
 * 오른쪽으로 이동과 글자 작성은 동일하고,
 * 왼쪽으로 이동과 글자 삭제는 동일
 * 즉 substring이 같은 시점까지 지우고 다시 쓰는 것과 방향키로 이동하는 것은 동일한 횟수를 차지
 */
int main() {
    char typo[101];
    char word[101];
    int i, count = 0;

    cin >> typo >> word;

    // 동일한 substring의 길이 확인
    for(i = 0; typo[i] && word[i] && typo[i] == word[i]; i++);

    // 지우거나 왼쪽으로 이동
    for(int idx = i; typo[idx]; idx++)
        count++;

    // 작성하거나 오른쪽으로 이동
    for(int idx = i; word[idx]; idx++)
        count++;

    // 생성, 삭제, 이동을 포함한 횟수 출력
    cout << count << endl;
    return 0;
}