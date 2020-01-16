#include <iostream>
#include <map>
using namespace std;

int collatzCycles(int n, map<int,int> &memo) {
    if (n == 1) return 1;
    if (memo[n] != 0) return memo[n];
    
    if (n%2) memo[n] = 1 + collatzCycles(3*n + 1, memo);
    else memo[n] = 1 + collatzCycles(n/2, memo);

    return memo[n];
}

int main() {
    int x, y;
    map<int, int> memo;

    while (cin >> x >> y) {
        int max = 0, current;
        int n = x, m = y;

        if (m < n) { 
            int temp = m;
            m = n;
            n = temp;
        }
        for (int i = n; i <= m; i++) {
            current = collatzCycles(i, memo);
            if (current > max) max = current;
        }
        cout << x << " ";
        cout << y << " ";
        cout << max << endl;
    }

    return 0;
}

