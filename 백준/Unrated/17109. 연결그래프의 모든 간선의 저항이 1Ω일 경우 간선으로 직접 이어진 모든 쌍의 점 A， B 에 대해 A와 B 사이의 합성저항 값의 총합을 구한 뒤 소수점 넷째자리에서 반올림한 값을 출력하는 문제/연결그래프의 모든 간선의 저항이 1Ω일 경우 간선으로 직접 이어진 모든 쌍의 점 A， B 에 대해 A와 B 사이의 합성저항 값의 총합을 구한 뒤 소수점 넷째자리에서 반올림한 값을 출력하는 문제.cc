#include <iostream>
#include <vector>

using namespace std;

// https://github.com/ghudegy/2019/blob/master/2nd-editorial.md#-%EC%97%B0%EA%B2%B0%EA%B7%B8%EB%9E%98%ED%94%84%EC%9D%98-%EB%AA%A8%EB%93%A0-%EA%B0%84%EC%84%A0%EC%9D%98-%EC%A0%80%ED%95%AD%EC%9D%B4-1%CF%89%EC%9D%BC-%EA%B2%BD%EC%9A%B0-%EA%B0%84%EC%84%A0%EC%9C%BC%EB%A1%9C-%EC%A7%81%EC%A0%91-%EC%9D%B4%EC%96%B4%EC%A7%84-%EB%AA%A8%EB%93%A0-%EC%8C%8D%EC%9D%98-%EC%A0%90-a-b-%EC%97%90-%EB%8C%80%ED%95%B4-a%EC%99%80-b-%EC%82%AC%EC%9D%B4%EC%9D%98-%ED%95%A9%EC%84%B1%EC%A0%80%ED%95%AD-%EA%B0%92%EC%9D%98-%EC%B4%9D%ED%95%A9%EC%9D%84-%EA%B5%AC%ED%95%9C-%EB%92%A4-%EC%86%8C%EC%88%98%EC%A0%90-%EB%84%B7%EC%A7%B8%EC%9E%90%EB%A6%AC%EC%97%90%EC%84%9C-%EB%B0%98%EC%98%AC%EB%A6%BC%ED%95%9C-%EA%B0%92%EC%9D%84-%EC%B6%9C%EB%A0%A5%ED%95%98%EB%8A%94-%EB%AC%B8%EC%A0%9C
int main() {
    int m, n;
    cin >> m >> n;
    
    if(!n)
        cout << 0 << ".000" << endl;
    else
        cout << (m - 1) << ".000" << endl;
    return 0;
}