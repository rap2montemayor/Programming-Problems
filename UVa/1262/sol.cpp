#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

bool in(char c, string &b) {
    for (char i : b)
        if (c == i) return true;
    return false;
}

vector<string> intersection(vector<string> &a, vector<string> &b) {
    vector<string> out;

    for (int i = 0; i < 5; i++) {
        string append = "";
        for (int j = 0; j < 6; j++)
            if (in(a[i][j], b[i])) append.push_back(a[i][j]);
        out.push_back(append);
    }

    return out;
}

void passGen(vector<string> &a, set<string> &out, string &current, int place = 0) {
    if (current.length() == 5) {
        out.insert(current);
        return;
    }
    for (int i = 0; i < a[place].length(); i++) {
        current.push_back(a[place][i]);
        passGen(a, out, current, place+1);
        current.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        vector<string> a(5,"AAAAAA");
        vector<string> b(5,"AAAAAA");

        cin >> n;
        for (int i = 0; i < 6; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 5; j++)
                a[j][i] = s[j];
        }
        for (int i = 0; i < 6; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 5; j++)
                b[j][i] = s[j];
        }
        
        vector<string>intersect = intersection(a, b);
        set<string> out;
        string current = "";
        passGen(intersect, out, current);
        
        if (n > out.size()) cout << "NO" << endl;
        else {
            set<string>::iterator it = out.begin();
            for (int i = 1; i < n; i++) it++;
            cout << *it << endl;
        }
    }
    return 0;
}
