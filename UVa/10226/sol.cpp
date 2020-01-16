#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

int main() {
    cout << fixed << setprecision(4);
    int n, total = 0;
    map<string, int> p;
    string s;

    cin >> n;
    getline(cin, s);
    getline(cin, s);

    while(n > 0) {
        getline(cin, s);
        if (s.empty()) {
            n--;
            for (pair<string, int> i : p) {
                double n = i.second;
                double d = total;
                if (i.second)
                    cout << i.first << " " << n/d*100 << endl;
            }
            if (n > 0) cout << endl;
            p.clear();
            total = 0;
            continue;
        }

        p[s]++;
        total++;
    }
    return 0;
}
