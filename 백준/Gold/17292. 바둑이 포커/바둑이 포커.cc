#include <iostream>
#include <string>

using namespace std;

string card_pair[15];

int Hex2Dec(char c) {
    if(c >= '0' && c <= '9')
        return c - '0';
    return (c - 'a') + 10;
}

bool IsContinuous(string p) {
    int num1 = Hex2Dec(p[0]);
    int num2 = Hex2Dec(p[2]);
    
    if((num1 == 1 && num2 == 15) || (num1 == 15 && num2 == 1))
        return true;
    else
        return abs(num1 - num2) == 1;
}

bool InnerOrder(string p1, string p2) {
    bool same_c1 = p1[1] == p1[3];
    bool same_c2 = p2[1] == p2[3];
    int big1 = max(Hex2Dec(p1[0]), Hex2Dec(p1[2]));
    int big2 = max(Hex2Dec(p2[0]), Hex2Dec(p2[2]));
    int small1 = min(Hex2Dec(p1[0]), Hex2Dec(p1[2]));
    int small2 = min(Hex2Dec(p2[0]), Hex2Dec(p2[2]));
    int big_c1, big_c2;

    // 1. 색이 같은 쌍
    if(same_c1 && !same_c2)
        return false;
    if(!same_c1 && same_c2)
        return true;

    // 2. 큰 수가 큰 쪽
    if(big1 > big2)
        return false;
    if(big1 < big2)
        return true;

    // 3. 작은 수가 큰 쪽
    if(small1 > small2)
        return false;
    if(small1 < small2)
        return true;
    
    // 4. 큰 수가 검은색
    if(Hex2Dec(p1[0]) < Hex2Dec(p1[2]))
        big_c1 = p1[3];
    else
        big_c1 = p1[1];

    if(Hex2Dec(p2[0]) < Hex2Dec(p2[2]))
        big_c2 = p2[3];
    else
        big_c2 = p2[1];
    
    // 두 수가 모두 같다면 하나는 black, 하나는 white
    if(big_c1 == 'b')
        return false;
    return true;
}

bool OuterOrder(string p1, string p2) {
    bool cont1 = IsContinuous(p1);
    bool cont2 = IsContinuous(p2);
    bool same1 = p1[0] == p1[2];
    bool same2 = p2[0] == p2[2];
    
    // 1. 연속된 수
    if(cont1 && cont2)
        return InnerOrder(p1, p2);
    if(cont1 && !cont2)
        return false;
    if(!cont1 && cont2)
        return true;

    // 2. 같은 수
    if(same1 && same2)
        return InnerOrder(p1, p2);
    if(same1 && !same2)
        return false;
    if(!same1 && same2)
        return true;
    
    // 3. 그 외
    return InnerOrder(p1, p2);
}

void Swap(string &a, string &b) {
    string tmp = a;
    a = b;
    b = tmp;
}

void MergeSort(int s, int e) {
    if(s == e)
        return;

    int m = (s + e) / 2;
    
    MergeSort(s, m);
    MergeSort(m + 1, e);

    string left[15];
    string right[15];
    int l_i = 0, r_i = 0;
    int l_end = m - s;
    int r_end = e - (m + 1);
    int index = 0;

    for(int i = 0; i <= l_end; i++)
        left[i] = card_pair[s + i];
    for(int i = 0; i <= r_end; i++)
        right[i] = card_pair[m + 1 + i];
    
    for(index = 0; l_i <= l_end && r_i <= r_end; index++) {
        if(OuterOrder(left[l_i], right[r_i]))
            card_pair[s + index] = right[r_i++];
        else
            card_pair[s + index] = left[l_i++];
    }

    for(; l_i <= l_end; index++)
        card_pair[s + index] = left[l_i++];

    for(; r_i <= r_end; index++)
        card_pair[s + index] = right[r_i++];
}

int main() {
    char num, color, delimiter;
    string card[6];

    for(int i = 0; i < 6; i++) {
        cin >> num >> color;

        card[i] = num;
        card[i] += color;

        if(i != 5)
            cin >> delimiter;
    }

    for(int i = 0, index = 0; i < 6; i++) {
        for(int j = i + 1; j < 6; j++)
            card_pair[index++] = card[i] + card[j];
    }

    MergeSort(0, 14);
    for(int i = 0; i < 15; i++)
        cout << card_pair[i] << '\n';
    return 0;
}