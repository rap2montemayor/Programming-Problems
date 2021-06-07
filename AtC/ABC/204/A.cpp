#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int x, y; cin >> x >> y;
    if (x == y) cout << x << '\n';
    else {
        int a[] = {0, 0, 0};
        a[x]++, a[y]++;
        if (a[0] == 0) cout << 0 << '\n';
        else if (a[1] == 0) cout << 1 << '\n';
        else  if (a[2] == 0) cout << 2 << '\n';
    }
    
    return 0;
}