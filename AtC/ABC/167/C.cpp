#include <bits/stdc++.h>
using namespace std;

int n,m,x;
int best = -1;

vector<vector<int>> A(12, vector<int>(12));
vector<int> C(12);
void bruteForce(int idx, int money, vector<int> &algo) {
    if (idx >= n) {
        bool achieved = true;
        for (int i : algo)
            if (i < x) achieved = false;
        if (achieved) {
            if (best==-1) best = money;
            else best = min(best,money);
        }
        return;
    }

    bruteForce(idx+1,money,algo);
    for (int i=0; i<m; i++)
        algo[i] += A[idx][i];
    bruteForce(idx+1, money+C[idx], algo);
    for (int i=0; i<m; i++)
        algo[i] -= A[idx][i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m>>x;
    vector<int> algo(m);
    for (int i=0; i<n; i++) {
        cin>>C[i];
        for (int j=0; j<m; j++)
            cin>>A[i][j];
    }
    bruteForce(0,0,algo);
    cout << best << '\n';

    return 0;
}