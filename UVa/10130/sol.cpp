#include <iostream>
#include <vector>
using namespace std;

int knapsackProblem(int row, int col, vector<int> &v, vector<int> &w, vector<vector<int>> &memo) {
    if (memo[row][col] != -1)
        return memo[row][col];
    if (row == 0) {
        if (col-w[row] < 0)
            memo[row][col] = 0;
        else
            memo[row][col] = v[row];
        return memo[row][col];
    }

    knapsackProblem(row-1,col,v,w,memo);
    if (col-w[row] >= 0)
        knapsackProblem(row-1,col-w[row],v,w,memo);

    if (col-w[row] < 0)
        memo[row][col] = memo[row-1][col];
    else {
        if (memo[row-1][col] > v[row]+memo[row-1][col-w[row]])
            memo[row][col] = memo[row-1][col];
        else
            memo[row][col] = v[row]+memo[row-1][col-w[row]];
    }

    return memo[row][col];
}

vector<vector<int>> makeMemo(int rows, int cols) {
    vector<vector<int>> out;
    while (rows--) {
        vector<int> app(cols,-1);
        out.push_back(app);
    }

    return out;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        vector<int> w(n);
        for (int i = 0; i < n; i++)
            cin >> v[i] >> w[i];

        int p; cin >> p;
        vector<int> f(p);
        for (int i = 0; i < p; i++)
            cin >> f[i];

        int ans = 0;
        for (int i : f) {
            vector<vector<int>> memo = makeMemo(n, i+1);
            ans += knapsackProblem(v.size()-1, i, v, w, memo);
        }

        cout << ans << endl;
    }
    return 0;
}
