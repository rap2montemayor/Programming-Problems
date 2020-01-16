#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string &s) {
    for (int i = 0; i < s.length()/2; i++)
        if (s[i] != s[s.length()-1-i]) return false;
    return true;
}

string evalBitmask(string &s, int bitmask) {
    string masked = "";
    for (int i = 0; i < s.length(); i++)
        if (bitmask & 1<<i) masked.push_back(s[i]);
    return masked;
}

string llps(string &s) {
    vector<string> palindromes;
    for (int bitmask = 0; bitmask < 1<<s.length(); bitmask++) {
        string masked = evalBitmask(s, bitmask);
        if (isPalindrome(masked)) palindromes.push_back(masked);
    }

    sort(palindromes.begin(), palindromes.end());
    return palindromes.back();
}

int main() {
    string s;
    cin >> s;
    cout << llps(s) << endl;
    return 0;
}
