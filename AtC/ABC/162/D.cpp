#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    string s; cin>>s;

    int ans=0;
    for (int i=0; i<n; ++i) {
        for (int j=i; j<n; ++j) {
            for (int k=j; k<n; ++k) {
                if (j-i == k-j) continue;
                if (s[i]==s[j]) continue;
                if (s[i]==s[k]) continue;
                if (s[j]==s[k]) continue;
                ++ans;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}