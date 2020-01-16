#include <bits/stdc++.h>
using namespace std;

bool match(string &s, string &t) {
    for (int i=0; i<s.size(); i++)
        if (s[i]!=t[i]) return false;
    return true;
}

int main() {
    int n; cin>>n;
    string s,t; cin>>s>>t;
    vector<pair<int,int>> answers;
    
    int matches=-1;
    for (int i=0; i<n; i++) {
        if (s[i] != t[i]) {
            bool sameIndexSwitch=true;
            for (int j=matches+1; j<n; j++) {
                if (j==i) continue;
                if (s[i]!=t[j] and t[j]!=s[j]) {
                    char temp=s[i];
                    s[i]=t[j];
                    t[j]=temp;
                    sameIndexSwitch=false;
                    answers.push_back({i,j});
                    break;
                }
            }
            if (sameIndexSwitch) {
                char temp=s[i];
                s[i]=t[i];
                t[i]=temp;
                answers.push_back({i,i});
            }
        }
        
        if (s[matches+1]==t[matches+1]) matches++;
    }

    if (s==t) {
        cout << answers.size() << endl;
        for (pair<int,int> p : answers)
            cout << p.first+1 << ' ' << p.second+1 << endl;
    }
    else cout << -1 << endl;
    return 0;
}
