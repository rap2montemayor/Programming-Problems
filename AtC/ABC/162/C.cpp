#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 2e9;

int gcdTable[201][201];
int gcd(int a, int b) {
    if (gcdTable[a][b] != -1)
        return gcdTable[a][b];
    int ans = b==0 ? a : gcd(b, a%b);
    gcdTable[a][b] = ans;
    gcdTable[b][a] = ans;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(gcdTable, -1, sizeof gcdTable);
    int k; cin>>k;
    int ans=0;
    for (int a=1; a<=k; a++) {
        for (int b=1; b<=k; b++) {
            for (int c=1; c<=k; c++) {
                int temp = gcd(a,b);
                temp = gcd(temp,c);
                ans += temp;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}