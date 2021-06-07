#include <bits/stdc++.h>
using namespace std;

int count0(string &s) {
    int ans = 0;
    for (char c : s)
        if (c == '0') ++ans;
    return ans;
}

void solve(int n, string &s) {
    if ((n & 1) and count0(s) > 1 and s[n/2] == '0')
        cout << "ALICE\n";
    else cout << "BOB\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        solve(n, s);
    }
    
    return 0;
}