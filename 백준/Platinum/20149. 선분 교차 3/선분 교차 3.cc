#include <iostream>
#define INF 10000000

using namespace std;
using ll = long long;
using Pos = pair<ll, ll>;
using Pdd = pair<double, double>;
using Matrix = pair<Pdd, Pdd>;

int CCW(Pos a, Pos b, Pos c) {
    ll outer_product = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
    return (outer_product > 0) - (outer_product < 0);
}

double Determinant2x2(Matrix mat) {
    return mat.first.first * mat.second.second - mat.first.second * mat.second.first;
}

Matrix DeterminantBlock2x2(Matrix mat11, Matrix mat12, Matrix mat21, Matrix mat22) {
    Matrix block;
    block.first.first = Determinant2x2(mat11);
    block.first.second = Determinant2x2(mat12);
    block.second.first = Determinant2x2(mat21);
    block.second.second = Determinant2x2(mat22);
    return block;
}

// https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
Pdd GetIntersect(Pdd a_start, Pdd a_end, Pdd b_start, Pdd b_end) {
    Matrix a = {a_start, a_end};
    Matrix b = {b_start, b_end};
    Matrix a_x = {{a_start.first, 1}, {a_end.first, 1}};
    Matrix a_y = {{a_start.second, 1}, {a_end.second, 1}};
    Matrix b_x = {{b_start.first, 1}, {b_end.first, 1}};
    Matrix b_y = {{b_start.second, 1}, {b_end.second, 1}};

    double intersect_x = Determinant2x2(DeterminantBlock2x2(a, a_x, b, b_x));
    double intersect_y = Determinant2x2(DeterminantBlock2x2(a, a_y, b, b_y));
    double intersect_p = Determinant2x2(DeterminantBlock2x2(a_x, a_y, b_x, b_y));

    if(intersect_p)
        return {intersect_x / intersect_p, intersect_y / intersect_p};

    if(a_end == b_start && a_start <= b_start)
        return a_end;
    else if(b_end == a_start && b_start <= a_start)
        return b_end;
    return {INF, INF};
}

int main() {
    cout.precision(16);
    cout << fixed;

    Pos a_start, a_end, b_start, b_end;
    int atob, btoa;
    Pdd intersect;

    cin >> a_start.first >> a_start.second >> a_end.first >> a_end.second;
    cin >> b_start.first >> b_start.second >> b_end.first >> b_end.second;

    atob = CCW(a_start, a_end, b_start) * CCW(a_start, a_end, b_end);
    btoa = CCW(b_start, b_end, a_start) * CCW(b_start, b_end, a_end);

    if(atob == 0 && btoa == 0) {
        Pos tmp;
    
        if(a_start > a_end) {
            tmp = a_start;
            a_start = a_end;
            a_end = tmp;
        }

        if(b_start > b_end) {
            tmp = b_start;
            b_start = b_end;
            b_end = tmp;
        }

        if(a_end < b_start || b_end < a_start)
            cout << "0\n";
        else {
            cout << "1\n";
            intersect = GetIntersect(a_start, a_end, b_start, b_end);
            if(intersect != Pdd(INF, INF))
                cout << intersect.first << ' ' << intersect.second << '\n';
        }
    }
    else {
        if(!(atob <= 0 && btoa <= 0))
            cout << "0\n";
        else {
            cout << "1\n";
            intersect = GetIntersect(a_start, a_end, b_start, b_end);
            if(intersect != Pdd(INF, INF))
                cout << intersect.first << ' ' << intersect.second << '\n';
        }
    }
    return 0;
}