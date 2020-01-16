#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<string> evalBitmask(int bitmask, vector<string> &volunteers) {
    set<string> out;
    for (int i = 0; i < volunteers.size(); i++)
        if (bitmask & 1<<i) out.insert(volunteers[i]);

    return out;
}

bool validTeam(set<string> &team, set<set<string>> &incompatible) {
    for (set<string> s : incompatible) {
        int n = 0;
        for (string str : s)
            if (binary_search(team.begin(), team.end(), str)) n++;
        if (n > 1) return false;
    }
    return true;
}

set<string> teamGen(vector<string> &volunteers, set<set<string>> &incompatible) {
    set<string> out;
    int bitmask = 1;
    while (bitmask < 1<<volunteers.size()) {
        set<string> team = evalBitmask(bitmask, volunteers);
        if (validTeam(team, incompatible) & team.size() > out.size())
            out = team;
        bitmask++;
    }

    return out;
}

int main() {
    int n, m;
    vector<string> volunteers;
    set<set<string>> incompatible;

    cin >> n >> m;
    volunteers.resize(n);
    for (int i = 0; i < n; i++)
        cin >> volunteers[i];

    while (m--) {
        string s;
        set<string> incompat;
        cin >> s;
        incompat.insert(s);
        cin >> s;
        incompat.insert(s);
        incompatible.insert(incompat);
    }

    set<string> team = teamGen(volunteers, incompatible);
    cout << team.size() << endl;
    for (string s : team) cout << s << endl;
    return 0;
}
