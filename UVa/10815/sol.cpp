#include <bits/stdc++.h>
using namespace std;

vector<string> getAllWords(string s) {
    vector<string> out;
    string word;
    for (int i=0; i<s.size(); i++) {
        if (s[i] >= 'a' and s[i] <= 'z')
            word.push_back(s[i]);
        else if (s[i] >= 'A' and s[i] <= 'Z')
            word.push_back(s[i] + ('a'-'A'));
        else if (word!="") {
            out.push_back(word);
            word="";
        }

        if (i==s.size()-1 and word!="")
            out.push_back(word);
    }

    return out;
}

int main() {
    set<string> words;
    string s;

    while (getline(cin, s)) {
        vector<string> v = getAllWords(s);
        for (string s : v) words.insert(s);
    }

    for (string s : words) cout << s << endl;
    return 0;
}
