#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> a;
    set<int> team;
    int n; cin>>n;
    while (n--) {
        int x; cin>>x;
        a.insert(x);
    }

    for (int i : a) {
        if (!team.count(i-1) and i>1)
            team.insert(i-1);
        else if (!team.count(i))
            team.insert(i);
        else if (!team.count(i+1))
            team.insert(i+1);
    }

    cout << team.size() << endl;
    return 0;
}
