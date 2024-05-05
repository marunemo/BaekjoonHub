#include <iostream>
#include <algorithm>

using namespace std;

int book[100000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int book_count;
    int start, count;

    cin >> book_count;
    for(int i = 0; i < book_count; i++)
        cin >> book[i];
    sort(book, book + book_count);

    start = book[0];
    count = 1;
    for(int i = 1; i < book_count; i++) {
        if(start * 2 <= book[i]) {
            count++;
            start = book[i];
        }
    }

    cout << count << endl;
    return 0;
}