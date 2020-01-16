#include <iostream>
#include <set>
#include <map>
using namespace std;

map<int, set<multiset<int>>> facs;

bool isPrime(int n) {
    for (int i = 2; i <= n/2; i++)
        if (n%i == 0) return false;
    return true;
}

set<multiset<int>> genfactorizations(int n) {
    set<multiset<int>> out;
    if (facs.count(n))
        return facs[n];
    if (isPrime(n)) {
        multiset<int> ms;
        ms.insert(n);
        out.insert(ms);
        return out;
    }
    for (int i = 2; i <= n; i++) {
        if (n%i == 0) {
            set<multiset<int>> s = genfactorizations(n/i);
            for (multiset<int> ms : s) {
                ms.insert(i);
                ms.erase(1);
                if (!ms.empty())
                    out.insert(ms);
            }
        }
    }

    facs[n] = out;
    return out;
}

int main() {
    int n;
    
    while (cin >> n) {
        if (n == 0) break;
        set<multiset<int>> ms = genfactorizations(n);
        ms.erase({n});

        cout << ms.size() << endl;
        for (multiset<int> s : ms) {
            multiset<int>::iterator it = s.begin();
            while (it != s.end()) {
                cout << *it;
                it++;
                if (it != s.end()) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
