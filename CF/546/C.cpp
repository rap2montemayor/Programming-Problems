#include <bits/stdc++.h>
using namespace std;

void fight(deque<int> &soldier1, deque<int> &soldier2) {
    int card1 = soldier1.front();    
    int card2 = soldier2.front();
    soldier1.pop_front();    
    soldier2.pop_front();
    
    if (card1 > card2) {
        soldier1.push_back(card2);
        soldier1.push_back(card1);
    }
    else {
        soldier2.push_back(card1);
        soldier2.push_back(card2);
    }
}

bool comp(deque<int> &d1, deque<int> &d2) {
    if (d1.size() != d2.size()) return false;
    auto it1 = d1.begin();
    auto it2 = d2.begin();
    while (it1 != d1.end()) {
        if (*it1 != *it2) return false;
        ++it1;
        ++it2;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    deque<int> soldier11, soldier12, soldier21, soldier22;
    int k; cin>>k;
    for (int i=0; i<k; i++) {
        int card; cin>>card;
        soldier11.push_back(card);
        soldier21.push_back(card);
    }
    cin>>k;
    for (int i=0; i<k; i++) {
        int card; cin>>card;
        soldier12.push_back(card);
        soldier22.push_back(card);
    }

    int fights = 0;
    while (!soldier21.empty() and !soldier22.empty()) {
        fights++;
        fight(soldier11, soldier12);
        fight(soldier21, soldier22);
        if (!soldier21.empty() and !soldier22.empty()) {
            fight(soldier21, soldier22);
            fights++;
        }
        if (soldier11 == soldier21 and soldier12 == soldier22)
            break;
    }

    if (!soldier21.empty() and !soldier22.empty())
        cout << "-1" << endl;
    else {
        cout << fights << ' ';
        if (soldier21.empty()) cout << 2 << endl;
        else cout << 1 << endl;
    }

    return 0;
}