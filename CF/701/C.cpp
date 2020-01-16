#include <bits/stdc++.h>
using namespace std;

map<char,int> firstIndex;
string s; 

int main() {
    int n; cin>>n;
    cin>>s;

    int ans=100001;
    for (pair<char, int> p : firstIndex) {
        int l=p.second, r=p.second+1;
        set<char> chars;
        
        chars.insert(s[l]);
        while (r<n) {
            chars.insert(s[r]);
            if (chars.size()==firstIndex.size() and r-l+1 < ans) ans = r-l+1;
            if (s[r] == s[l]) l++;
            r++;
        }
    }
 
    if (lastIndex.size()==1) cout << 1 << endl;
    else cout << ans << endl;
    return 0;
}
