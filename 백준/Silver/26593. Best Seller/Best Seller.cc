#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    string name;
    int sales;
    double profit;
};

bool Compare(Item a, Item b) {
    if(a.sales * a.profit != b.sales * b.profit)
        return a.sales * a.profit > b.sales * b.profit;
    
    if(a.sales != b.sales)
        return a.sales > b.sales;

    return a.name < b.name;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    string name;
    int sales;
    double profit;
    Item item;
    vector<Item> list;

    while(cin >> name >> sales >> profit) {
        item.name = name;
        item.sales = sales;
        item.profit = profit;

        list.push_back(item);
    }
    sort(list.begin(), list.end(), Compare);

    cout.precision(2);
    cout << fixed;

    for(Item item: list)
        cout << '$' << (item.sales * item.profit) << " - " << item.name << '/' << item.sales << '\n';
    return 0;
}