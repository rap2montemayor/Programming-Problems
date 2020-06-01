#include <bits/stdc++.h>
using namespace std;

string s,t;
int dp[3001][3001], trace[3001][3001][2];
int solve(int i, int j) {
    if (i >= s.size()) return 0;
    if (j >= t.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans;
    if (s[i] == t[j]) {
        ans = 1 + solve(i+1,j+1);
        trace[i][j][0] = i+1;
        trace[i][j][1] = j+1;
    }
    else {
        int temp1 = solve(i+1, j);
        int temp2 = solve(i, j+1);
        ans = max(temp1,temp2);

        if (temp1 > temp2) {
            trace[i][j][0] = i+1;
            trace[i][j][1] = j;
        }
        else {
            trace[i][j][0] = i;
            trace[i][j][1] = j+1;
        }
    }

    dp[i][j] = ans;
    return ans;
}

string getLCS() {
    string res = "";
    int ch = 0, i = 0, j = 0;
    while (ch < dp[0][0]) {
        int nxti = trace[i][j][0];
        int nxtj = trace[i][j][1];

        if (nxti>i and nxtj>j) {
            res += s[i];
            ch++;
        }
        i = nxti;
        j = nxtj;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>s>>t;
    memset(dp, -1, sizeof dp);
    solve(0,0);
    cout << getLCS() << endl;

    return 0;
}