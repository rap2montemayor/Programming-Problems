#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    for (int i=1; i<=t; i++) {
        int n; cin>>n;
        int ans=0;
        string field;
        cin >> field;
        field+="##";
        for (int i=1; i<n+2; i++) {
            if (field[i-1]=='.') {
                ans++;
                i+=2;
            }
        }

        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
