#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin>>s;
    string hello="hello";
    int hellop=0;
    
    for (int i=0; i<s.length(); i++) {
        if (s[i]==hello[hellop]) hellop++;
        if (hellop==5) break;
    }

    if (hellop==5) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
