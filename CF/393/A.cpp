#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin>>s;
    vector<int> chars(26);
    for (char c : s) chars[c-'a']++;
    cout << min({chars['n'-'a']/2, chars['i'-'a'], chars['e'-'a']/3, chars['t'-'a']}) << endl; 
    return 0;
}

//hmmrmhrmsjhrjjsmhmmmrsmjhjhmrm
//
//n 4  -> 2
//i 8  -> 8
//e 6  -> 2
//t 10 -> 10
