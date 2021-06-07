#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int ans = 0;
    while ((ans << 1) + 1 < n)
        ans = (ans<<1) + 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << solve(n) << '\n';
    }
    
    return 0;
}