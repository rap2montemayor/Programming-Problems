#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k; cin>>n>>k;
    int a[n], dp[2][k+1];
    memset(dp, 0, sizeof dp);
    for (int i=0; i<n; i++)
        cin>>a[i];
    //player 1 is 0
    //player 2 is 1

    for (int i=0; i<n; i++)
        dp[0][k-a[i]] = 1;
    
    int i=0;
    while (true) {
        bool moved=false;
        for (int j=0; j<=k; j++) {
            if (dp[i][j] == 1) {
                for (int move=0; move<n; move++) {
                    if (j-a[move] >= a[0]) {
                        dp[(i+1)%2][j-a[move]] = 1;
                        moved=true;
                    }
                }
            }
        }
        if (!moved) break;
        i = (i+1) % 2;
    }

    cout << i << '\n';
    return 0;
}