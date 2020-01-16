#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int n, k, q;
    map<int, int> relation;
    set<int> out;

    cin >> n >> k >> q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        relation[i] = x;
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            out.insert(y);
            if (out.size() > k) {
                int min = *(out.begin());
                for (int i : out) if (relation[i] < relation[min]) min = i;
                out.erase(min);
            }
        }

        else {
            if (out.count(y)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
