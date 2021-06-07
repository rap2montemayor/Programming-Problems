#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, a[1000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 10) continue;
        else ans += a[i]-10;
    }
    cout << ans << '\n';
    
    return 0;
}