#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while (t--) {
        int n,m; cin>>n>>m;
        n-=2; m-=2;
        int x = n/3;
        int y = m/3;

        if (n%3 != 0) x++;
        if (m%3 != 0) y++;

        cout << x*y << endl;
    }
    return 0;
}
