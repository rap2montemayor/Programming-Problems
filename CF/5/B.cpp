#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> lines;
    string s;
    int width=0;
    while (getline(cin,s)) {
        lines.push_back(s);
        if (s.size()>width)
            width=s.size();
    }

    for (int i=0; i<width+2; i++) cout<<'*';
    cout << endl;

    bool left=0;
    for (string s : lines) {
        cout << '*';
        if ((width-s.size())%2==1 and left) cout<<' ';
        for (int i=0; i<(width-s.size())/2; i++) cout<<' ';
        cout << s;
        for (int i=0; i<(width-s.size())/2; i++) cout<<' ';
        if ((width-s.size())%2==1 and !left) cout<<' ';
        cout << '*' << '\n';

        if ((width-s.size())%2==1) left=!left;
    }
    
    for (int i=0; i<width+2; i++) cout<<'*';
    cout << endl;
    return 0;
}
