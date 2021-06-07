#include <bits/stdc++.h>
using namespace std;

int n, a[50];

int solve() {
    bool sorted = true;
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i-1]) sorted = false;
    
    if (sorted) return 0;
    else if (a[0] == 1 or a[n-1] == n) return 1;
    else if (a[0] == n and a[n-1] == 1) return 3;
    else return 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << solve() << '\n';
    }
    return 0;
}