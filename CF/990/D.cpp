#include <iostream>
#include <vector>
using namespace std;

void getComplement(vector<vector<int>> &G) {
    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < G.size(); j++) {
            if (j == i) continue;
            if (G[i][j] == 1) G[i][j] = 0;
            else G[i][j] = 1;
        }
    }
}

vector<vector<int>> buildGraph(int n, int a, int b) {
    vector<vector<int>> G(n,vector<int>(n));
    if (a == 1) {
        for (int i = 0; i < n-b; i++) {
            G[i][i+1] = 1;
            G[i+1][i] = 1;
        }
        getComplement(G);
    }
    else if (b == 1) {
        for (int i = 0; i < n-a; i++) {
            G[i][i+1] = 1;
            G[i+1][i] = 1;
        }
    }

    return G;
}

int main() {
    int n,a,b;
    cin >> n >> a >> b;

    if (a > 1 and b > 1) {
        cout << "NO" << endl;
        return 0;
    }
    if ( (n==2 or n==3) and (a == 1 and b == 1) ) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    vector<vector<int>> G = buildGraph(n, a, b);
    for (vector<int> v : G) {
        for (int i : v) cout << i;
        cout << endl;
    }
    return 0;
}
