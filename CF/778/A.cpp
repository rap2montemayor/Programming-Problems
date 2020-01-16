#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
bool check(string t, string &p, vector<int> &rm, int n) {
    for (int i = 0; i < n; i++) {
        t[rm[i]-1] = ' ';
    }
    int pi = 0;
    for (int i = 0; i < t.length(); i++) {
        if (t[i] == p[pi]) pi++;
        if (pi == p.length()) return true;
    }
 
    return false;
}
 
int main() {
    string t,p;
    vector<int> rm;
    cin >> t >> p;
 
    for (char c : t) {
        int x;
        cin >> x;
        rm.push_back(x);
    }
 
    int upper = t.length() - p.length() + 1;
    int lower = 1;
    int mid;
 
    while (lower < upper) {
        mid = (upper+lower) / 2;
        if (check(t, p, rm, mid)) { lower = mid + 1; }
        else { upper = mid; }
    }
 
    cout << lower-1 << endl;
    return 0;
}
