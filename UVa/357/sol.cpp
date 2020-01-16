#include <iostream>
#include <vector>
using namespace std;

vector<int> coins = {1, 5, 10, 25, 50};
vector<vector<long long>> memo;

long long count(int n, int row = 4) {
    if (memo[row][n] != -1) return memo[row][n];
    if (row == 0) return 1;

    memo[row][n] = 0;
    for (int i = n; i >= 0; i -= coins[row])
        memo[row][n] += count(i, row-1);

    return memo[row][n];
}

int main() {
    int n;
    
    vector<long long> v(30001, 1);
    memo.push_back(v);
    for (int i = 0; i < 5; i++) {
        vector<long long> v(30001, -1);
        memo.push_back(v);
    }
        
    while (cin >> n) {
        long long ans = count(n);

        if (ans == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << ans << " ways to produce " << n << " cents change." << endl;
    }
    return 0;
}
