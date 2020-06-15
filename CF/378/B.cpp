#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> a(n+1, 2e9), b(n+1, 2e9);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    vector<bool> semi1(n), semi2(n);
    // k = 0
    int l = 0, r = 0;
    for (int i=0; i<n; i++) {
        if (a[l] < b[r])
            semi1[l++] = true;
        else
            semi2[r++] = true;
    }

    // k = n/2
    if (n > 1)
        for (int i=1; i*2<=n; i++)
            semi1[i-1] = semi2[i-1] = true;
    
    for (int i : semi1) cout << i; cout << endl;
    for (int i : semi2) cout << i; cout << endl;
    return 0;
}