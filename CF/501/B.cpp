#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    int n;
    map<string, string> orig;
    set<string> used;
    cin >> n;

    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;
        
        if (used.count(s1)) {
            for (pair<string, string> x : orig)
                if (x.second == s1) orig[x.first] = s2;
            used.insert(s2);
        }
        else {
            orig[s1] = s2;
            used.insert(s1);
            used.insert(s2);
        }
    }

    cout << orig.size() << endl;
    for (pair<string, string> x : orig)
        cout << x.first << " " << x.second << endl;
    return 0;
}
