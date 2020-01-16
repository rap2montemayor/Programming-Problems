#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> digitcount(10);
        while (n) {
            int x=n;
            while (x>0) {
                digitcount[x%10]++;
                x/=10;
            }
            n--;
        }

        for (int i=0; i<10; i++) {
            cout << digitcount[i];
            if (i!=9) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
