#include <bits/stdc++.h>
using namespace std;

bool isOpen(char c) {
    return c == '(' or c == '[' or c == '{' or c == '<';
}

bool isClose(char c) {
    return c == ')' or c == ']' or c == '}' or c == '>';
}

vector<int> solve(string &s) {
    vector<int> ans(s.size()), update(s.size());
    stack<int> open;

    map<char, char> match;
    match['('] = ')';
    match['['] = ']';
    match['<'] = '>';
    match['{'] = '}';

    for (int i=0; i<s.size(); i++) {
        if (isOpen(s[i])) open.push(i);
        else if (!open.empty() and match[s[open.top()]] == s[i]) {
            update[i] = i - open.top() + 1;
            open.pop();
        }
        else
            while (!open.empty())
                open.pop();
    }

    vector<bool> done(s.size());
    for (int i = update.size() - 1; i >= 0; i--) {
        if (update[i] == 0 or done[i]) continue;
        for (int j = i; j >= 0; j -= update[j]) {
            if (update[j] == 0) break;
            ans[j - update[j] + 1] = i - (j - update[j] + 1) + 1;
            done[j] = true;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    for (int c = 1; c <= t; c++) {
        string s; cin>>s;
        vector<int> ans = solve(s);
        cout << "Case " << c << ":\n";
        for (int i : ans)
            cout << i << '\n';
    }
    return 0;
}