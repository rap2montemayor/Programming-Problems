#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3;

vector<char> get_unique() {
    set<char> charset;
    vector<char> chars;
    for (char c : s1+s2+s3) {
        if (not charset.count(c)) {
            charset.insert(c);
            chars.push_back(c);
        }
    }
    return chars;
}

bool check(map<char, int> &digit) {
    string sn1, sn2, sn3;
    for (char c : s1) sn1.push_back(digit[c] + '0');
    for (char c : s2) sn2.push_back(digit[c] + '0');
    for (char c : s3) sn3.push_back(digit[c] + '0');

    if (sn1[0] == '0' or sn2[0] == '0' or sn3[0] == '0')
        return false;
    long long n1 = stoll(sn1), n2 = stoll(sn2), n3 = stoll(sn3);
    return n1 + n2 == n3;
}

bool assign(int idx, map<char, int> &digit, vector<char> &chars, vector<bool> &taken) {
    if (idx >= chars.size())
        return check(digit);

    bool done = false;
    for (int i = 0; i < 10; ++i) {
        if (taken[i]) continue;
        taken[i] = true;
        digit[chars[idx]] = i;
        
        done = assign(idx+1, digit, chars, taken);
        if (done) break;

        digit[chars[idx]] = 1;
        taken[i] = false;
    }

    return done;
}

void print_ans(map<char,int> &digit) {
    for (char c : s1)
        cout << digit[c];
    cout << '\n';
    
    for (char c : s2)
        cout << digit[c];
    cout << '\n';

    for (char c : s3)
        cout << digit[c];
    cout << '\n';
}

void solve() {
    vector<char> chars = get_unique();
    vector<bool> taken(10);
    map<char, int> digit;

    if (chars.size() > 10) {
        cout << "UNSOLVABLE\n";
        return;
    }

    if (assign(0, digit, chars, taken))
        print_ans(digit);
    else
        cout << "UNSOLVABLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s1 >> s2 >> s3;
    solve();

    return 0;
}