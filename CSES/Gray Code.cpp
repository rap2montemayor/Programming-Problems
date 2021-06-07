#include <bits/stdc++.h>
using namespace std;

void printbits(int bits, int n) {
    for (int i = bits-1; i >= 0; --i)
        cout << ((n & (1<<i)) ? 1 : 0);
    cout << '\n';
}

void solve(int bits) {
    vector<int> sol;
    sol.reserve(1<<16);
    sol.resize(2);
    sol[0] = 0, sol[1] = 1;
    for (int i = 1; i < bits; ++i) {
        for (int j = sol.size()-1; j >= 0; --j) {
            sol.push_back(sol[j] | (1<<i));
        }
    }
    
    for (int i : sol)
        printbits(bits, i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int bits; cin >> bits;
    solve(bits);
    
    return 0;
}