#include <iostream>
#include <set>
using namespace std;
 
int main() {
    int n;
    set<int> dists;
    set<int> ans;

    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        dists.insert(x);
    }
    ans.insert(*(dists.begin()));

    for (int i : dists) {
        for (int j = 0; j < 31; j++) {
            int diff = 1 << j;
            if (dists.count(i-diff) and dists.count(i+diff))
                ans = { i-diff, i, i+diff };
            else if (dists.count(i-diff) and ans.size() < 2)
                ans = { i-diff, i };
            else if (dists.count(i+diff) and ans.size() < 2)
                ans = { i, i+diff };
        }
    }
 
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl; 
    return 0;
}
