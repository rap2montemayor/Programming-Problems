#include <bits/stdc++.h>
using namespace std;

int t, dp[2000][2000];
bool vis[2000][2000];
string a,b;
int getEDist(int i, int j) {
    if (min(i,j)==-1) return max(i,j)+1;
    if (vis[i][j]) return dp[i][j];
    vis[i][j] = true; 

    if (a[i]==b[j]) dp[i][j] = getEDist(i-1,j-1);
    else dp[i][j] = 1 + min({
        getEDist(i-1,j-1),
        getEDist(i,  j-1),
        getEDist(i-1,j  )
    });

    return dp[i][j];
}

int main() {
    cin>>t;
    while (t--) {
        cin>>a>>b;
        memset(dp,0,sizeof dp);
        memset(vis,false,sizeof vis);
        cout << getEDist(a.size()-1,b.size()-1) << '\n';
    }
    return 0;
}